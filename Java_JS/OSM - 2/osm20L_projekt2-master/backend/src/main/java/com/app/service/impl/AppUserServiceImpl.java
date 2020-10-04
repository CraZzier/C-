package com.app.service.impl;

import com.app.model.AppUser;
import com.app.repo.AppUserRepo;
import com.app.service.AppUserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.transaction.Transactional;

import java.util.List;
import java.util.Set;

@Service
@Transactional
public class AppUserServiceImpl implements AppUserService {

    @Autowired
    AppUserRepo appUserRepo;

    @Override
    public AppUser saveUser(String name, String surname, Long pesel) {
        AppUser appUser = new AppUser();
        appUser.setName(name);
        appUser.setSurname(surname);
        appUser.setPesel(pesel);

        appUserRepo.save(appUser);
        return appUser;
    }

    @Override
    public AppUser findUserById(int id) {
        return appUserRepo.findAppUserById(id);
    }

    @Override
    public AppUser findByPesel(Long pesel) {
        return appUserRepo.findAppUserByPesel(pesel);
    }

    @Override
    public List<AppUser> userList() {
        return appUserRepo.findAll();
    }
}
