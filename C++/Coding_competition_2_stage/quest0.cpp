#include <stdio.h>
using namespace std;

int main(){
    int wynik[100];
    int dane[100][3];
    int t,temp;
    scanf("%d" ,&t);
    for(int i=0;i<t;i++){
        scanf("%d", &temp);
        dane[i][0] = temp;
        scanf("%d", &temp);
        dane[i][1] = temp;
        scanf("%d", &temp);
        dane[i][2] = temp;
    }
    for(int i=0;i<t;i++){
        if(dane[i][1]<dane[i][2] && dane[i][0]!=0){
            wynik[i]=0;
            continue;
        }
        if(dane[i][1]/dane[i][2]<dane[i][0]){
            wynik[i]=0;
        }else{
            wynik[i]=1;
        }
    }
    for(int i=0;i<t;i++){
        if(wynik[i]==1){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}
