import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule} from '@angular/forms';
import { CommonModule } from '@angular/common';
import { HttpClientModule } from '@angular/common/http';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ErrorComponent } from './error/error.component';
import { ZarejestrujComponent } from './zarejestruj/zarejestruj.component';
import { ProfilComponent } from './profil/profil.component';
import { DodajComponent } from './dodaj/dodaj.component';
import { BadaniaComponent } from './badania/badania.component';

import { StoreService } from './store.service';
import { MenuComponent } from './menu/menu.component';
import { LightboxModule } from 'ngx-lightbox';

@NgModule({
  declarations: [
    AppComponent,
    ErrorComponent,
    ZarejestrujComponent,
    ProfilComponent,
    DodajComponent,
    BadaniaComponent,
    MenuComponent,
  ],
  imports: [
    CommonModule,
    HttpClientModule,
    BrowserModule,
    AppRoutingModule,
    FormsModule,
    LightboxModule,
  ],
  providers: [
    StoreService
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
