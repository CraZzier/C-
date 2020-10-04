Read.me
<h1>osm_20L_projekt2</h1>

<h6>
Jan Grzegorek
Witold Synowiec
</h6>
 
Prezentacja aplikacji:
<https://www.youtube.com/watch?v=Lg_s1895Pgc>
</p>
 
<p>
O aplikacji
Aplikacja służy do rejestrowania użytkowników, przypisywania im obrazu dicom oraz wyświetlania go. Program nie umożliwia usuwania badań , ani usuwania użytkowników.
Ponadto zrezygnowaliśmy z wprowadzenia zabezpieczeń, gdyż uznaliśmy ,że nie jest to kluczowy element naszego projektu. Jest to jednak użyteczność która może być dodana.
Projekt natomiast został rozszerzony o dynamiczne dodawanie i odczyt z serwera zadanego pliku. Innymi słowy plik wrzucony na serwer może być od razu odczytany bez zresetowania serwera. 

Do napisania programu użyliśmy:
Po stronie frontendu Angulara w wersji Angular: 9.1.9 , “Angularowej” linii komend Angular CLI: 9.1.7 oraz npm. Oprócz tego do urozmaicenia szaty graficznej i ogólnie pojmowanego stylu wizualnego zostały użyte biblioteki css oraz js należące do bibliotek: bootstrap4, alertify, ngx-lightbox.

Po stronie backendu użyte zostały: Tomcat, Maven, Java Spring (w tym Java Persistant API,  JDBC, Spring Boot Starter Web) oraz biblioteka dcm4chee. 

Użyte IDE: Intellij IDEA
Baza danych: MySQL z dodatkiem do obsługi Workbench.


Aby zobaczyć profil użytkownika i archiwum jego obrazu dicom, należy na poslużyć się wyszukiwarką na stronie “/zarejestruj”. Szczegóły użycia będą umieszczone pod paragrafem.Do napisania programu użyliśmy po stronie frontendu Angulara w wersji Angular: 9.1.9 , “Angularowej” linii komend Angular CLI: 9.1.7 oraz npm. 
</p>
<p>Baza danych:
*Upewnić się że są zainstalowane: 
(sugerujemy) MySQLWorkbench 	<https://dev.mysql.com/downloads/workbench/>
mySQL 				<https://dev.mysql.com/downloads/mysql/>

Projekt wykorzystuje domyślnie bazę danych o parametrach:
nazwa bazy danych: 		osm
username: 			root
password:			root
W celu zmienienia parametrów bazy należy w katalogu projektu otworzyć plik application.properties w katalogu resources (backend/src/main/resources). Można tam zmienić parametry nazwy bazy danych, username i password na odpowiadającej własnej bazie danych.

W celu przejrzenia rekordów w MySQLWorkbench należy uruchomieniu connections otworzyć zakładkę schema. Po lewej stronie okienka znajdzie się (po uruchomieniu backendu!) schemat bazy danych o nazwie osm (domyślnie)

*baza danych wykorzystuje kanał localhost:3306 (należy się upewnić czy jest zwolniony przed uruchomieniem programu)*
</p>
<p>
Uruchomienie frontendu:
*Upewnić się że są zainstalowane: 
-Node.js		<https://nodejs.org/en/>
-Angular CLI*		<https://angular.io/>

W celu zainstalowania Angular CLI należy w linii komend terminalu wpisać
>npm install -g @angular/cli
W celu uruchomienia aplikacji należy przejść do folderu projektu frontend oraz wywołać z terminala komendę:
>ng serve

*aplikacja frontend domyślnie działa na kanale localhost:4200 (należy się upewnić czy jest zwolniony przed uruchomieniem programu)*
</p>

<p>
Uruchomienia backendu:
*środowisko Intellij*
Po uruchomieniu IDE należy wykonać operacje:
File -> Open oraz otworzyć folder projektu oraz przejść do folderu backend
Projekt powinien się załączyć i być gotowy do uruchomienia. 
Jeśli nie:
w drzewie projektu ustawić folder java (w src/main) na sources root (rpm Mark direcotry as -> source root)
w drzewie projektu ustawić folder resources (w src/main) na resources root (rpm Mark direcotry as -> resource root)
Edit Configurations -> Spring Boot Application lub Java Application
Należy się upewnić czy załączone są zewnętrzne biblioteki (dcm4che). W tym celu File->Project Structure->Modules->plus na prawym panelu->Jar or Directories i dodać (sprawdzić czy są dodane) wszystkie pliki jar z katalogu src/main/java/lib
następnie kliknąć Run Project

*aplikacja backend domyślnie działa na kanale localhost:8080 (należy się upewnić czy jest zwolniony przed uruchomieniem programu)*
</p>
