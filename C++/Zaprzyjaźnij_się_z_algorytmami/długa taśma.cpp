#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//Declaration of variables
int n,s;
int tab[1000002];
int pre[1000002];
int naj=100000000;
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++){
   scanf("%d",&tab[i]);
   naj=min(naj,tab[i]);
}
double najw=naj;
printf("%.2lf",najw);
}
