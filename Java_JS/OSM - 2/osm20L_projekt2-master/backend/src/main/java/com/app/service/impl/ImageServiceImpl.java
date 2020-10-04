package com.app.service.impl;

import com.app.BackendApplication;
import com.app.model.AppUser;
import com.app.model.Image;
import com.app.repo.ImageRepo;
import com.app.service.ImageService;
import com.app.util.Constants;
import org.dcm4che3.tool.dcm2jpg.Dcm2Jpg;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;

import javax.imageio.ImageIO;
import javax.transaction.Transactional;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

import static java.lang.StrictMath.abs;

@Service
@Transactional
public class ImageServiceImpl implements ImageService {

    @Autowired
    ImageRepo imageRepo;
    private ResourceHandlerRegistry register;

    @Override
    public List<Image> imageList() {
        return imageRepo.findAll();
    }

    @Override
    public List<Image> findImagesByPesel(Long pesel) {
        return imageRepo.findImagesByOwnerPesel(pesel);
    }

    @Override
    public Image getImageById(int id) {
        return imageRepo.findImageById(id);
    }

    @Override
    public String saveImageFile(AppUser appUser, MultipartFile multipartFile, String fileName) {
        try {
            Image image = new Image();
            image.setOwnerPesel(appUser.getPesel());

            SimpleDateFormat curdate = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss:SSS-Z");
            Date date = Calendar.getInstance().getTime();
            String curdateString = curdate.format(date);
            int hashCurdate = abs(curdateString.hashCode());
            String hashedFileNameDcm = hashCurdate + ".dcm";
            String hashedFileNameJpg = hashCurdate + ".jpg";
            System.out.println(hashedFileNameDcm);
            System.out.println(hashedFileNameJpg);


            Path path = Paths.get(Constants.USER_FOLDER + hashedFileNameDcm);
            Path path1 = Paths.get(Constants.USER_FOLDER + hashedFileNameJpg);

            image.setLocation(Constants.USER_FOLDER + hashedFileNameDcm);
            imageRepo.save(image);
            byte[] bytes = multipartFile.getBytes();
            Files.write(path, bytes, StandardOpenOption.CREATE);
            try {
                File src = new File(Constants.USER_FOLDER + hashedFileNameDcm);
                File dest = new File(Constants.USER_FOLDER + hashedFileNameJpg);
                Dcm2Jpg dcm2jpg = new Dcm2Jpg();
                dcm2jpg.initImageWriter("jpg", ".jpg", null, null, null);
                dcm2jpg.convert(src, dest);
                BufferedImage bimage = ImageIO.read(new File(Constants.USER_FOLDER + hashedFileNameJpg));
                ByteArrayOutputStream bos = new ByteArrayOutputStream();
                ImageIO.write(bimage, "jpg", bos);
                System.out.println("Completed jpg");
                byte[]data =bos.toByteArray();
                Files.write(path1,data, StandardOpenOption.CREATE);
                System.out.println("Completed");
            } catch (Exception e) {
                e.printStackTrace();
            }


        } catch (IOException e) {
            System.out.println("Error occured. Photo not saved!");
            return "Error occured. Photo not saved!";
        }
        System.out.println("Photo saved successfully!");
        return "Photo saved successfully!";
    }


}
