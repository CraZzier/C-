#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//Declaration of variables
int n;
int a,b;
vector<pair<int,int> >tab;
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    tab.push_back(make_pair(a,b));
}
sort(tab.begin(),tab.end());
int odl=tab[0].second;
int wynik=1000000005;
for(int i=1;i<n;i++){
    odl+=(tab[i].first-tab[i-1].first);
    wynik=min(wynik,odl+tab[i].second);
    odl=min(odl,tab[i].second);
}
cout<<wynik;
}
