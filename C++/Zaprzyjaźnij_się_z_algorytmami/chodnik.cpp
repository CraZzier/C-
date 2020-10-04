#include <cstdio>
using namespace std;
long long liczba;
long long x;
long long wynik=0;
int main(){
scanf("%lld",&liczba);
long long rez=liczba *(liczba+1)/2;
for(long long i=0;i+1<liczba;i++){
   scanf("%lld",&x);
   wynik+=x;
}
wynik=rez-wynik;
printf("%lld",wynik);
}

