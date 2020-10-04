#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//Declaration of variables
int n,k;
int wynik=0;
int najw=0;
unsigned int tab[1000001];
int main(){
scanf("%d%d",&n,&k);
for(int i=0;i<n;i++){
    scanf("%ud",&tab[i]);
}
sort(tab,tab+n);
for(int i=0;i<n-k-1;i++){
    if(tab[i]==tab[i+1]){
        wynik++;
    }else{
        wynik=0;
    }
    najw=max(wynik,najw);
}
wynik=min(n,najw+k+1);
printf("%d",wynik);
}
