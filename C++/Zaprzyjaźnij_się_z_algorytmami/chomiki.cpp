#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//Declaration of variables
int n,m;
int a,b;
int t[500001];
int tab[5][500001];
int main(){
scanf("%d%d",&n,&m);
for(int i=0;i<5;i++){
   tab[i][0]=0;
}
for(int i=1;i<=n;i++){
   scanf("%d",&t[i]);
   t[i]=t[i]-1;
   for(int p=0;p<=4;p++){
      if(t[i]==p){
         tab[p][i]=tab[p][i-1]+1;

      }else{
         tab[p][i]=tab[p][i-1];
      }
   }
}
for(int i=1;i<=m;i++){
   scanf("%d%d",&a,&b);
   for(int p=0;p<5;p++){
      if(tab[p][b]-tab[p][a-1]>0){
        cout<<p+1<<endl;
         break;
      }
   }
}
}
