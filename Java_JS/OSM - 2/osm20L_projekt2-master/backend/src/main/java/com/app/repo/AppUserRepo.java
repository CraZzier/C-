package com.app.repo;

import com.app.model.AppUser;
import org.springframework.data.jpa.repository.JpaRepository;

public interface AppUserRepo extends JpaRepository<AppUser, Integer> {

    public AppUser findAppUserById(int i);

    public AppUser findAppUserByPesel(Long i);
}
