#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
long long int a,b;
bool tab[3][1096];
void k(){
for(int i=0;i<2;i++){
	for(int j=0;j<1095;j++){
		tab[i][j]=false;
	}
}
}
int a2a10(long long int a){
	int wynik=0;
	int i=0;
	while(abs(a)>0){
		wynik+=a%10 * pow(2,i);
		a=a/10;
		i++;
	}
	return wynik;
}
int a4a10(long long int a){
	int wynik=0;
	int i=0;
	while(abs(a)>0){
		wynik+=a%10 * pow(4,i);
		a=a/10;
		i++;
	}
	return wynik;
}
int a8a10(long long int a){
	int wynik=0;
	int i=0;
	while(abs(a)>0){
		wynik+=a%10 * pow(8,i);
		a=a/10;
		i++;
	}
	return wynik;
}
int a10a2(long long int a){
	int i=0;
	int wyn=0;
	while(abs(a)>0){
		wyn=wyn+ceil(((a%2)*pow(10,i)));
		a/=2;
		i++;
	}
	return wyn;
}
int najn=9999999;
int main(){
	ifstream pobieranie;
	ofstream zapis;
	zapis.open("wyniki.txt");
	pobieranie.open("dane_systemy1.txt", ios::in);
	for(int i=0;i<1095;i++){
		pobieranie>>a>>b;
		najn=min(najn,a2a10(b));
	}
	zapis<<a10a2(najn)<<endl;
	pobieranie.close();
	pobieranie.open("dane_systemy2.txt", ios::in);
	najn=99999999;
	for(int i=0;i<1095;i++){
		pobieranie >> a >>b;
		najn=min(najn,a4a10(b));
	}
	zapis<<a10a2(najn)<<endl;
	pobieranie.close();
	pobieranie.open("dane_systemy3.txt", ios::in);
	najn=99999999;
	for(int i=0;i<1095;i++){
		pobieranie >> a >>b;
		najn=min(najn,a8a10(b));
	}
	zapis<<a10a2(najn)<<endl;
	pobieranie.close();

k();
pobieranie.open("dane_systemy1.txt", ios::in);
for(int i=0;i<1095;i++){
	pobieranie>>a>>b;
	if(a2a10(a)!=12+(i)*24){
		tab[0][i]=true;
	}
}
pobieranie.close();
pobieranie.open("dane_systemy2.txt", ios::in);
for(int i=0;i<1095;i++){
	pobieranie>>a>>b;
	cout<<a4a10(a)<<endl;
	if(a4a10(a)!=12+((i)*24)){
		tab[1][i]=true;
	}
}
pobieranie.close();
pobieranie.open("dane_systemy3.txt", ios::in);
for(int i=0;i<1095;i++){
	pobieranie>>a>>b;
	if(a8a10(a)!=12+(i)*24){
		tab[2][i]=true;
	}
}
pobieranie.close();
int wyn=0;
for(int i=0;i<1095;i++){
	if(tab[0][i]==true &&tab[1][i]==true &&tab[2][i]==true){
		wyn++;
	}
}
zapis<<wyn;
int taab[1096];
int maxi=-9999999;
for(int i=0;i<1096;i++){
	taab[i]=false;
}
pobieranie.open("dane_systemy1.txt");
for(int i=0;i<1095;i++){
	pobieranie>>a>>b;
	if(a2a10(b)>maxi){
		maxi=a2a10(b);
		taab[i]=true;
	}
}
pobieranie.close();
maxi=-9999999;
pobieranie.open("dane_systemy2.txt");
for(int i=0;i<1095;i++){
	pobieranie>>a>>b;
	if(a4a10(b)>maxi){
		maxi=a4a10(b);
		taab[i]=true;
	}
}
pobieranie.close();
maxi=-9999999;
pobieranie.open("dane_systemy3.txt");
for(int i=0;i<1095;i++){
	pobieranie>>a>>b;
	if(a8a10(b)>maxi){
		maxi=a8a10(b);
		taab[i]=true;
	}
}
pobieranie.close();
int wy=0;
for(int i=0;i<1095;i++){
	if(taab[i]==true){
		wy++;
	}
}
zapis<<endl<<wy;
int ttab[1096];
int c,d;
pobieranie.open("dane_systemy1.txt");
for(int i=0;i<1095;i++){
	pobieranie>>a>>b;
	ttab[i]=a2a10(b);
}
double m=-999999;
int g,h;
for(int i=0;i<1095;i++){
	for(int j=i;j<1095;j++){
		m=max(m,ceil((double)((ttab[i]-ttab[j])*(ttab[i]-ttab[j]))/(j-i)));
	}
}
zapis<<endl<<m;
}
