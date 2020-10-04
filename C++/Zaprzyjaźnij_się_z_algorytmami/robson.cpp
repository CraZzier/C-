#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long a,b,c,d,n,m,x,y;

main()
{
	float A,a;
	float e = 0.0001; //dokladnosc

	cout << "Podaj liczbe do wyciagniecia pierwiastka: ";
	cin >> A;

	a=A/2;

while(fabs(a - A/a) > e)
{
a=(A/a+a)/2;
cout<<a<<endl;
}




}
