#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//Declaration of variables
int n;
int s;
int tab[1000005];
int main(){
scanf("%d",&n);
for(int i=0;i<=1000005;i++)
   tab[i]=0;
for(int i=0;i<n;i++){
   scanf("%d",&s);
   if(s<=n){
   tab[s]+=1;
   }else{
   cout<<"NIE";
   return 0;
   }
}
tab[0]=1;
for(int i=0;i<=n;i++){
   if(tab[i]!=1){
      cout<<"NIE";
      return 0;
   }
}
cout<<"TAK";
}
