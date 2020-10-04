package com.app.repo;

import com.app.model.Image;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface ImageRepo extends JpaRepository<Image, Integer> {
    public Image findImageById(int id);
    public List<Image> findImagesByOwnerPesel(Long pesel);
}
