package com.app.service;

import com.app.model.AppUser;
import com.app.model.Image;
import org.springframework.web.multipart.MultipartFile;

import java.util.HashMap;
import java.util.List;

public interface ImageService {

    public List<Image> imageList();

    public Image getImageById(int id);

    public String saveImageFile(AppUser appUser, MultipartFile multipartFile, String fileName);

    public List<Image> findImagesByPesel(Long pesel);
}
