#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//Declaration of variables
long long n;
long long wynik=0;
int point=1;
long long tab[1000003];
int main(){
scanf("%lld",&n);
for(int i=0;i<n;i++){
    scanf("%lld",&tab[i]);
}
for(int i=n-1;i>=0;){
    point=1;
    while(tab[i]<tab[i-point] && i-point>=0){
        point++;
    }
    wynik=wynik+tab[i]*point;
    i=i-point;
}
cout<<wynik;
}
