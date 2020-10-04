#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <conio.h>
using namespace std;
char x;

int beben1[26]={66,68,70,72,74,76,67,80,82,84,88,86,90,78,89,69,73,87,71,65,75,77,85,83,81,79};
int beben2[26]={65,74,68,75,83,73,82,85,88,66,76,72,87,84,77,67,81,71,90,78,80,89,70,86,79,69};
int beben3[26]={69,75,77,70,76,71,68,81,86,90,78,84,79,87,89,72,88,85,83,80,65,73,66,82,67,74};
 void zamiana(int tab[]){
	int a=tab[25];
	for(int i=0;i<25;i++){
		tab[i+1]=tab[i];
	}
	tab[0]=a;
 }
int main(){
while(1==1){
x=getchar();
x=beben1[x-65];
zamiana(beben1);
x=beben2[x-65];
x=beben3[x-65];
cout<<x;
}
}
