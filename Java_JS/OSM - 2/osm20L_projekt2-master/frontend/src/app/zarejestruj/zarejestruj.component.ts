import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { HttpErrorResponse } from '@angular/common/http';
import { StoreService } from '../store.service';

declare let alertify:any;


@Component({
  selector: 'app-zarejestruj',
  templateUrl: './zarejestruj.component.html',
  styleUrls: ['./zarejestruj.component.css']
})
export class ZarejestrujComponent implements OnInit {

  constructor(
    private storeService: StoreService,
    private router: Router,
  ) { }

  onRegister(user): void {
    console.log(user);
    let pesel = user.pesel;
    this.storeService.register(user).subscribe(
      response => {
        console.log(response);
        alertify.success("Zarejestrowano");
        this.router.navigateByUrl(`/${pesel}/profil`);
      },
      (error: HttpErrorResponse) => {
        console.log(error);
        alertify.error('Nie zarejestrowano');
      }
    );
  }
  findByPesel(searchForm){
    let pes = searchForm.pesel1;
    console.log(pes);
    this.router.navigateByUrl(`${searchForm.pesel1}/profil`);
  }
  ngOnInit(): void {
  }

}
