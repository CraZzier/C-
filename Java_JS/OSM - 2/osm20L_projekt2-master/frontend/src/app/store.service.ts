import { Injectable } from '@angular/core';
import { HttpClient, HttpErrorResponse, HttpResponse } from '@angular/common/http';
import { Observable } from 'rxjs';

import { User } from './model/user';
import { Imgs } from './model/imgs';
import { ServerConstant } from './constant/server-constant';

@Injectable({
  providedIn: 'root'
})
export class StoreService {

  constant: ServerConstant = new ServerConstant();
  public host = this.constant.host;
  public clientHost = this.constant.client;
  constructor(private http: HttpClient) {}

  register(user: User): Observable<User | HttpErrorResponse> {
    return this.http.post<User>(`${this.host}/zarejestruj`, user);
  }

  getUserInformation(pesel: string): Observable<User> {
    return this.http.get<User>(`${this.host}/${pesel}/profil`);
  }
  userAv(pesel: string): Observable<Boolean> {
    return this.http.get<Boolean>(`${this.host}/${pesel}/profil`);
  }
  getImgsByPesel(pesel: string): Observable<Imgs[]> {
    return this.http.get<Imgs[]>(`${this.host}/${pesel}/badania`);
  }

}
