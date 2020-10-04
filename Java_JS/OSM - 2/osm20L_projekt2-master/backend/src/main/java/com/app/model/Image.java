package com.app.model;

import javax.persistence.*;

@Entity
@Table(name = "IMAGES")
public class Image {

    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    @Column(nullable = false, updatable = false)
    private int id;

    @Column
    private Long ownerPesel;

    @Column
    private String location;

    public Image() {
    }

    public Image(int id, Long ownerPesel, String location) {
        this.id = id;
        this.ownerPesel = ownerPesel;
        this.location = location;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Long getOwnerPesel() {
        return ownerPesel;
    }

    public void setOwnerPesel(Long ownerPesel) {
        this.ownerPesel = ownerPesel;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }
}
