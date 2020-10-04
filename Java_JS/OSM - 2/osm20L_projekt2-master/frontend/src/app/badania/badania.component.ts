import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { StoreService } from '../store.service';
import { Router, ActivatedRoute, Params } from '@angular/router';
import { HttpErrorResponse } from '@angular/common/http';
import { User } from '../model/user';
import { Imgs } from '../model/imgs';
import { ImgsTrans } from '../model/imgstrans';
import { LightboxModule, Lightbox } from 'ngx-lightbox';
import { LightboxConfig } from 'ngx-lightbox';

declare let alertify:any;

@Component({
  selector: 'app-badania',
  templateUrl: './badania.component.html',
  styleUrls: ['./badania.component.css']
})
export class BadaniaComponent implements OnInit {
  private _album: Array<any> = [];
  host: string;
  pesel:string;
  user: User;
  imgs:Imgs[];
  imgstrans:ImgsTrans[];
  size:number;


  constructor(
    private _lightboxConfig: LightboxConfig,
    private http:HttpClient,
    private route: ActivatedRoute,
    public storeService: StoreService,
    private router:Router,
    private _lightbox: Lightbox
    
    ) { 
      _lightboxConfig.centerVertically = true;
    }

    getProperImage(event){
      console.log(event.target);
      document.querySelector("img").src = event.target.dataset.path;
    }
    open(event){
      try{this._album.pop()}catch{}
      let srcIm = event.target.dataset.path;
      console.log(srcIm.slice(-3,srcIm.length));
      if(srcIm.slice(-3,srcIm.length)=="dcm"){
        srcIm = srcIm.replace("dcm","jpg");
      }
      console.log(srcIm);
      const album = {
        src: srcIm,
        caption: " ",
        thumb: srcIm,
     };
     this._album.push(album);
     this._lightbox.open(this._album, 0);
    }
    ngOnInit(): void {
      this.imgstrans = new Array();
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
          this.storeService.getImgsByPesel(this.pesel).subscribe(
            (response: Imgs[]) => {
              this.imgs = response;
              this.size = this.imgs.length;

              for(let i=0;i<this.imgs.length;i++){
                
                if(this.imgs[i].location == null){
                  this.imgstrans[i] = new ImgsTrans();
                  this.imgstrans[i].name = "brak";
                  this.imgstrans[i].fullPath = "brak";
                }else{
                  let href = this.imgs[i].location;
                  let point = href.lastIndexOf('/');
                  let shortpath = href.slice(point+1,href.length);
                  let fullpath = this.host + '/image/' + shortpath;
                  this.imgstrans[i] = new ImgsTrans();
                  this.imgstrans[i].name = shortpath;
                  this.imgstrans[i].fullPath = fullpath;
                }
                
              }
            },
            error => {
              alertify.error("Błąd");
              console.log(error);
              this.user = null;
              this.router.navigateByUrl('/zarejestruj');
            }
          );
        },
        error => {
          alertify.error("Nie znaleziono, wracasz do rejestracji");
          console.log(error);
          this.user = null;
          this.router.navigateByUrl('/zarejestruj');
        }
      );
    }

}
