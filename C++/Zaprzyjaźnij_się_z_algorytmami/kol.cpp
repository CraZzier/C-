#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <int>janek;
void pierwsze(int a){
for(int i=2;i<a;i++){
	for(int j=i+i;j<a;j=j+i){
		janek[j]=1;
	}
}
}
void liczby(int a){
vector <int> karo;
karo.resize(a);
pierwsze(a);
for(int i=1;i<a;i++){
	if((a%i)==0){
		if(janek[i]==0){
			cout<<i<<" ";
		}
	}
}

}
int karolinka;
main(){
cin>>karolinka;
janek.resize(karolinka);
liczby(karolinka);

}

