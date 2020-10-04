import { Component, OnInit } from '@angular/core';
import { Router, ActivatedRoute, Params } from '@angular/router';
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-menu',
  templateUrl: './menu.component.html',
  styleUrls: ['./menu.component.css']
})
export class MenuComponent implements OnInit {
  pesel:String

  constructor(
    private http:HttpClient,
    private route: ActivatedRoute,
    private router:Router,
    ){}

  ngOnInit(): void {
    try{
      this.pesel = this.route.snapshot.paramMap.get('pesel');
    }
    catch{
      this.pesel="0";
    }
  }
  changeLoc(loc:string){
    this.pesel = this.route.snapshot.paramMap.get('pesel');

    let point = this.router.url.lastIndexOf('/');
    let pes = this.router.url.slice(1,point+1);
    let url = '/'+pes+loc;
    console.log(loc);
    console.log(url);
    this.router.navigateByUrl(url);
  }

}
