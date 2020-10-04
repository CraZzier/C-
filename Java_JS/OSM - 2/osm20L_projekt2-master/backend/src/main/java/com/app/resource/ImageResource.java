package com.app.resource;


import com.app.model.AppUser;
import com.app.model.Image;
import com.app.service.AppUserService;
import com.app.service.ImageService;
import org.apache.commons.lang3.RandomStringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.util.HashMap;
import java.util.List;

@CrossOrigin(origins = "http://localhost:4200",maxAge = 3600)
@RestController
//@RequestMapping(value = "/image")
public class ImageResource {

    @Autowired
    ImageService imageService;

    @Autowired
    AppUserService appUserService;
    String imageName;

    @PostMapping("/{pesel}/dodaj")
    public ResponseEntity<String> fileUpload(@PathVariable("pesel") String pesel, @RequestParam("image") MultipartFile multipartFile) {
        AppUser user = getAppUser(Long.parseLong(pesel));
        if (user == null) {
            return new ResponseEntity<>("User Not Found", HttpStatus.NOT_FOUND);
        }
        String postImageName = multipartFile.getOriginalFilename();
        try {
            imageService.saveImageFile(user, multipartFile, postImageName);
            return new ResponseEntity<>("Picture Saved!", HttpStatus.OK);
        } catch (Exception e) {
            return new ResponseEntity<>("Picture was saved", HttpStatus.BAD_REQUEST);
        }
    }

    @GetMapping("/{pesel}/badania")
    public ResponseEntity<?> getImagesByPesel(@PathVariable("pesel") String pesel) {
        AppUser user = getAppUser(Long.parseLong(pesel));
        if (user == null) {
            return new ResponseEntity<>("User Not Found", HttpStatus.NOT_FOUND);
        }
        try {
            List<Image> posts = imageService.findImagesByPesel(Long.parseLong(pesel));
            return new ResponseEntity<>(posts, HttpStatus.OK);
        } catch (Exception e) {
            return new ResponseEntity<>("Error Occured", HttpStatus.BAD_REQUEST);
        }
    }

    private AppUser getAppUser(Long pesel) {
        return appUserService.findByPesel(pesel);
    }
}
