import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { StoreService } from '../store.service';
import { Router, ActivatedRoute, Params } from '@angular/router';
import { HttpErrorResponse } from '@angular/common/http';
import { User } from '../model/user';
declare let alertify:any;

@Component({
  selector: 'app-profil',
  templateUrl: './profil.component.html',
  styleUrls: ['./profil.component.css']
})
export class ProfilComponent implements OnInit {

  host: string;
  pesel:string;
  user: User;

  constructor(
    private http:HttpClient,
    private route: ActivatedRoute,
    public storeService: StoreService,
    private router:Router,
    ) { }

  ngOnInit(): void {
    this.user = new User();
    this.user.name=" ";
    this.user.surname=" ";
    this.user.pesel=0;
    this.host = this.storeService.host;
    this.pesel = this.route.snapshot.paramMap.get('pesel');
    this.storeService.userAv(this.pesel).subscribe(
      (response: Boolean) => {
        alertify.success("Znaleziono");
        this.storeService.getUserInformation(this.pesel).subscribe(
          (response: User) => {
            this.user = response;
          },
          error => {
            console.log(error);
            this.user = null;
            this.router.navigateByUrl('/zarejestruj');
          }
        );
      },
      error => {
        alertify.error("nie znaleziono, wracasz do rejestracji")
        console.log(error);
        this.user = null;
        this.router.navigateByUrl('/zarejestruj');
      }
    );

  }
 
}
