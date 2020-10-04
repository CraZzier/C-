#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//Declaration of variables
int tab[300005];
int n,m,s;
int licznik=0;
int main(){
for(int i=0;i<300005;i++){
   tab[i]=0;
}
scanf("%d%d",&n,&m);
for(int i=0;i<m;i++){
   scanf("%d",&s);
   if(s<=n&&tab[s]==0){
      tab[s]+=1;
      licznik++;
   }
   if(licznik==n){
      cout<<i+1;
      return 0;
   }
}
cout<<"-1";
}

