#include <cstdio>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
//Declaration of variables
int n,m,s;
int naj=0;
int wynik=0;
int ok=0;
int tab[1000001];
int main(){
scanf("%d%d",&n,&m);
memset (tab,0,8);
for(int i=1;i<=m;i++){
   scanf("%d",&s);
   if(s<=n&&wynik==0){
      tab[s]+=1;
      naj=max(naj,tab[s]);
   }
   if(s<=n&&wynik==1){
      if(tab[s]<ok)
      tab[s]=ok;
      tab[s]+=1;
      naj=max(naj,tab[s]);
   }
   if(s==n+1){
      wynik=1;
      ok=naj;
   }
}
for(int i=1;i<=n;i++){
      if(tab[i]<ok){
         printf("%d ",ok);
      }else{
         printf("%d ",tab[i]);}
}
}
