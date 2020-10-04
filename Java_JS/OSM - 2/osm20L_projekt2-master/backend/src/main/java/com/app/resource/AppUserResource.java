package com.app.resource;

import com.app.model.AppUser;
import com.app.service.AppUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.util.HashMap;
import java.util.List;

@CrossOrigin(origins = "http://localhost:4200", maxAge = 3600)
@RestController

public class AppUserResource {

    @Autowired
    AppUserService appUserService;

    @GetMapping("/list")
    public ResponseEntity<?> getUsersList() {
        List<AppUser> users = appUserService.userList();
        if (users.isEmpty()) {
            return new ResponseEntity<>("No Users Found.", HttpStatus.OK);
        }
        return new ResponseEntity<>(users, HttpStatus.OK);
    }

    @GetMapping("/{pesel}/profil")
    public ResponseEntity<?> getUserInfo(@PathVariable String pesel) {
        Long peselLong = Long.parseLong(pesel);
        AppUser user = appUserService.findByPesel(peselLong);
        if (user == null) {
            return new ResponseEntity<>("No Users Found.", HttpStatus.NOT_FOUND);
        }
        return new ResponseEntity<>(user, HttpStatus.OK);
    }

    @PostMapping("/zarejestruj")
    public ResponseEntity<?> register(@RequestBody HashMap<String, String> request) {
        String pesel = request.get("pesel");
        Long peselLong = Long.parseLong(pesel);
        if (appUserService.findByPesel(peselLong) != null) {
            return new ResponseEntity<>("peselExist", HttpStatus.CONFLICT);
        }
        String name = request.get("name");
        String surname = request.get("surname");
        try {
            AppUser user = appUserService.saveUser(name,surname ,peselLong);
            return new ResponseEntity<>(user, HttpStatus.OK);
        } catch (Exception e) {
            return new ResponseEntity<>("An error occured", HttpStatus.BAD_REQUEST);
        }
    }
}
