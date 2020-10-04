#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <int> tab;
string a;
void konwersja(string c,long long iter,int x){
    long long suma=0;
        for(int i=1;i<=c.length();i++){
            if(c[i-1]=='0'){
                suma=ceil(suma+0*pow(10,c.length()-i));
            }
            if(c[i-1]=='1'){
                suma=ceil(suma+1*pow(10,c.length()-i));
            }
            if(c[i-1]=='2'){
                suma=ceil(suma+2*pow(10,c.length()-i));
            }
            if(c[i-1]=='3'){
                suma=ceil(suma+3*pow(10,c.length()-i));
            }
            if(c[i-1]=='4'){
                suma=ceil(suma+4*pow(10,c.length()-i));
            }
            if(c[i-1]=='5'){
                suma=ceil(suma+5*pow(10,c.length()-i));
            }
            if(c[i-1]=='6'){
                suma=ceil(suma+6*pow(10,c.length()-i));
            }
            if(c[i-1]=='7'){
                suma=ceil(suma+7*pow(10,c.length()-i));
            }
            if(c[i-1]=='8'){
                suma=ceil(suma+8*pow(10,c.length()-i));
            }
            if(c[i-1]=='9'){
                suma=ceil(suma+9*pow(10,c.length()-i));
            }
        }
if(x==0)
    tab[iter]=suma;
if(x==1)
    tab[iter]=-suma;
};

int machina(string a){
string s;
a=a+" ";
int x=0;
int licz=0;
if(a[0]=='-'){
    x=1;
}
for(int i=0;i<a.length();i++){
    if(a[i]==' ' && a[i+1]!='-'&& i!=0){
        konwersja(s,licz,x);
        s="";
        licz++;
        x=0;
    }
    else if(a[i]==' ' && a[i+1]=='-'){
        konwersja(s,licz,x);
        s="";
        licz++;
        x=1;
    }else if(a[i]=='-'){
        continue;
    }
    else{
        s=s+a[i];
    }
}
return licz;
}


int main(){
getline(cin,a);//wczytanie dancyh

tab.resize(a.length());//okreœlenie wielkoœci tablicy

int howbigistab=machina(a);//wczytanie liczb do tablicy

for(int i=0;i<howbigistab;i++){//wypisanie tablicy
    cout<<tab[i]<<" ";
}

}

