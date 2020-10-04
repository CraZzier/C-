#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//Declaration of variables
int n,m;
int naj=0,najw;
long long najwy=1;
int mn=0,mni,mnie=1;
int t[3];
int tab[100001];
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++){
    najwy=1;
    scanf("%d",&m);
    for(int o=0;o<m;o++){
        scanf("%d",&tab[o]);
    }
    sort(tab,tab+m);
    if(tab[0]*tab[1]>tab[m-2]*tab[m-3]&&tab[m-1]>0){
         najwy=tab[0]*tab[1]*tab[m-1];
    }else{
        najwy=tab[m-1]*tab[m-2]*tab[m-3];
    }
        printf("%d\n",najwy);
    }
}

