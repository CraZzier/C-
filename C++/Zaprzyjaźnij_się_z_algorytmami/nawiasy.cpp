#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
//Declaration of variables
int n;
int f=0;
int s=0;
string sign;
vector <char> stos;
string tab[258];
int main(){
cin>>n;
for(int i=0;i<n;i++){
    tab[i]="NIE";
}
for(int p=0;p<n;p++){
        cin>>sign;
        f=0;
        s=0;
        stos.clear();
        for(int i=0;i<sign.length();i++){
            if(sign[i]=='{' || sign[i]=='[' || sign[i]=='('){
                stos.push_back(sign[i]);
                f++;
            }else{
                s++;
                if(sign[i]==')'){
                    if(stos.back()=='('){
                        stos.pop_back();
                       }else{
                        tab[i]="NIE";
                        break;
                       }
                }
                if(sign[i]=='}'){
                    if(stos.back()=='{'){
                        stos.pop_back();
                       }else{
                        tab[i]="NIE";
                        break;
                       }
                }
                if(sign[i]==']'){
                    if(stos.back()=='['){
                        stos.pop_back();
                       }else{
                        tab[i]="NIE";
                        break;
                       }
                }
                }
        }

        if(f==s && stos.empty()){
               tab[p]="TAK";
            }else{
               tab[p]="NIE";
            }
}
for(int i=0;i<n;i++){
 cout<<tab[i]<<endl;
}
}
