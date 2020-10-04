import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { StoreService } from '../store.service';
import { Router, ActivatedRoute, Params } from '@angular/router';
import { HttpErrorResponse } from '@angular/common/http';
import { User } from '../model/user';
declare let alertify:any;

@Component({
  selector: 'app-dodaj',
  templateUrl: './dodaj.component.html',
  styleUrls: ['./dodaj.component.css']
})
export class DodajComponent implements OnInit {

  dodane=null;
  host: string;
  pesel:string;
  user: User;

  constructor(
    private http:HttpClient,
    private route: ActivatedRoute,
    public storeService: StoreService,
    private router:Router,
    
    ) { }

  onFileSelected(event){
    this.dodane = <File>event.target.files[0];
    console.log(this.dodane);
  }

  onFileSubmited(){
    let fd = new FormData();
    fd.append( 'image',this.dodane, this.dodane.name);
    console.log(fd);
    this.http.post(`${this.host}/${this.pesel}/dodaj`, fd,{responseType: 'text'}).subscribe(
      response => {
        console.log(response);
        alertify.success("Wysłano");
      },
      (error: HttpErrorResponse) => {
        console.log(error);
        alertify.error('Nie wysłano');
      }
    );
  }

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
