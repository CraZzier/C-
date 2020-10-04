package com.app.service;

import com.app.model.AppUser;

import java.util.List;

public interface AppUserService {

    public AppUser saveUser(String name, String surname, Long pesel);

    public AppUser findUserById(int id);

    public AppUser findByPesel(Long pesel);

    public List<AppUser> userList();


}
