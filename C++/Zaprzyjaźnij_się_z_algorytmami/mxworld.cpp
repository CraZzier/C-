#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include  <cstring>
#include <iomanip>
using namespace std;
double kasa=0;
double start=0;
string linijka;
string pom;
string b="ok";
double oblicz(string o){
double suma=0;
int i=0;
int przed=0;
while(o[i]!='.'){
	i++;
	przed++;
}
for(int i=0;i<przed;i++){
		  if(o[i]=='0'){
                suma+=0*pow(10,przed-1-i);
            }
            if(o[i]=='1'){
                suma+=1*pow(10,przed-1-i);
            }
            if(o[i]=='2'){
                suma+=2*pow(10,przed-1-i);
            }
            if(o[i]=='3'){
                suma+=3*pow(10,przed-1-i);
            }
            if(o[i]=='4'){
                suma+=4*pow(10,przed-1-i);
            }
            if(o[i]=='5'){
                suma+=5*pow(10,przed-1-i);
            }
            if(o[i]=='6'){
                suma+=6*pow(10,przed-1-i);
            }
            if(o[i]=='7'){
                suma+=7*pow(10,przed-1-i);
            }
            if(o[i]=='8'){
                suma+=8*pow(10,przed-1-i);
            }
            if(o[i]=='9'){
                suma+=9*pow(10,przed-1-i);
            }
}
int u=0;
int x=0;
while(o[i]!=' '){
		  if(o[i]=='0'){
                suma+=0*pow(10,u);
                x++;
            }
            if(o[i]=='1'){
                suma+=1*pow(10,u);
            }
            if(o[i]=='2'){
                suma+=2*pow(10,u);
            }
            if(o[i]=='3'){
                suma+=3*pow(10,u);
            }
            if(o[i]=='4'){
                suma+=4*pow(10,u);
            }
            if(o[i]=='5'){
                suma+=5*pow(10,u);
            }
            if(o[i]=='6'){
                suma+=6*pow(10,u);
            }
            if(o[i]=='7'){
                suma+=7*pow(10,u);
            }
            if(o[i]=='8'){
                suma+=8*pow(10,u);
            }
            if(o[i]=='9'){
                suma+=9*pow(10,u);
            }
            u--;
            i++;
}
return suma;

}


string ty;
int main(){
ifstream odczyt;
double mainsume=0;
odczyt.open("mx.txt",ios::in );
while(!odczyt.eof()){
getline(odczyt,linijka);
cout<<linijka<<endl;
pom="";
int i=0;
while(linijka[i]!=' '){
	pom+=linijka[i];
	i++;
}
if(pom=="Expired"){
	continue;
}
while(linijka[i]==' '){
	i++;
}
pom="";
while(linijka[i]!='\t'){
	pom+=linijka[i];
	i++;
}
pom+=' ';

while(linijka[i]=='\t'){
	i++;
}
ty="";
while(linijka[i]!='\t' && i<linijka.length()){
	ty+=linijka[i];
	i++;
}
start=0;;
if(ty=="Mini"){
	start=5.5;
}
if(ty=="Medium"){
	start=27.5;
}
if(ty=="Millionaire"){
	start=55;
}
mainsume+=(start-oblicz(pom))/2.0;cout<<mainsume<<endl;
}
odczyt.close();
cout<<mainsume;
}
