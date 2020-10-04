#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//Declaration of variables
int n;
long long suma=0;
int tab[1000002];
int pre[1000002];
int main(){
   tab[0]=0;
   pre[0]=0;
scanf("%d",&n);
for(int i=1;i<=n;i++){
   scanf("%d",&tab[i]);
}
for(int i=1;i<=n;i++){
   if(tab[i]==0){
      pre[i]=pre[i-1]+1;
   }else{
      pre[i]=pre[i-1];
   }
}
for(int i=1;i<=n;i++){
   if(tab[i]==1){
      suma+=pre[i];
   }
}
cout<<suma;
}
