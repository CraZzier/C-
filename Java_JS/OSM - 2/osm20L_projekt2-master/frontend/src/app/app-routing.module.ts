import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { AppComponent } from './app.component';
import { ZarejestrujComponent } from './zarejestruj/zarejestruj.component';
import {ErrorComponent} from './error/error.component';
import {ProfilComponent} from './profil/profil.component';
import {DodajComponent} from './dodaj/dodaj.component';
import {BadaniaComponent} from './badania/badania.component';

const routes: Routes = [
  { path: 'zarejestruj', component:ZarejestrujComponent},
  { path: ':pesel/profil', component: ProfilComponent},
  { path: ':pesel/dodaj', component: DodajComponent},
  { path: ':pesel/badania', component: BadaniaComponent},
  { path: '', redirectTo: '/zarejestruj',pathMatch: 'full'},
  { path: '**', component: ErrorComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
