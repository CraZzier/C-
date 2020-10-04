import { Component, OnInit } from '@angular/core';
import { Router, ActivatedRoute, Params } from '@angular/router';

declare let alertify:any;
@Component({
  selector: 'app-error',
  templateUrl: './error.component.html',
  styleUrls: ['./error.component.css']
})
export class ErrorComponent implements OnInit {

  constructor(
    private router:Router,
  ) { }

  ngOnInit(): void {
    alertify.error("Nie jesteś na stronie użytkownika albo wpisaleś złą ścieżkę");
    this.router.navigateByUrl('zarejestruj');
  }

}
