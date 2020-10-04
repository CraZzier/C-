#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int wynik;
    int r,s, po_ile, reszta;
    int razy;

    scanf("%d %d",&r,&s);

    razy = pow(2,r);
    if(s==0){
        wynik = pow(2,r);
    }else{
        po_ile = s/r;
        reszta = s%r;
        if(reszta==0){
            wynik = razy * ceil(pow((po_ile+1),r));
        }else{
            wynik = razy * ceil(pow((po_ile+1),(r-reszta)))* ceil(pow((po_ile+2), reszta));
        }
    }
    printf("%llu",wynik);

    return 0;
}
