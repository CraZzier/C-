#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//Declaration of variables
int n,s;
int wynik=0;
int stos[1000001][2];
vector <int> crucial;
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d",&s);
    stos[i][0]=s;
}
for(int i=0;i<n;i++){
    scanf("%d",&s);
    stos[i][1]=s;
}
for(int i=n-1;i>=0;i--){
    if(stos[i][1]==0){
        crucial.push_back(stos[i][0]);
    }else{
        if(crucial.size()==0){
            wynik++;
        }else{
        while(crucial.back()<stos[i][0] && crucial.size()>0){
            crucial.pop_back();
        }
        if(crucial.size()==0){
            wynik++;
        }
        }
    }
}
wynik=wynik+crucial.size();
cout<<wynik;

}
