#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
long long int n=0;
long long int tab[10000000];
long long int suma=0;

int main(){
scanf("%lld",&n);
for(int i=0;i<n;i++){
   scanf("%lld",&tab[i]);
   suma+=tab[i];
   tab[i]=suma;
}
long long int wynik=5000001;
for(long long int i=0;i<n;i++){
   wynik=min(wynik,abs(tab[i]-suma+tab[i]));
}
cout<<wynik;
}
