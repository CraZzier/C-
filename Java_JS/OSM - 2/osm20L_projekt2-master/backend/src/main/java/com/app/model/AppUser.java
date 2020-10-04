package com.app.model;

import javax.persistence.*;
import java.util.List;

@Entity
@Table(name = "APPUSERS")
public class AppUser {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    @Column(nullable = false, updatable = false)
    private int id;

    @Column
    private String name;

    @Column
    private String surname;

    @Column
    private Long pesel;

    @OneToMany(cascade = CascadeType.ALL, fetch = FetchType.EAGER)
    private List<Image> images;

    public AppUser() {
    }

    public AppUser(int id, String name, String surname, Long pesel, List<Image> images) {
        this.id = id;
        this.name = name;
        this.surname = surname;
        this.pesel = pesel;
        this.images = images;
    }




    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public Long getPesel() {
        return pesel;
    }

    public void setPesel(Long pesel) {
        this.pesel = pesel;
    }

    public List<Image> getImages() {
        return images;
    }

    public void setImages(List<Image> images) {
        this.images = images;
    }
}
