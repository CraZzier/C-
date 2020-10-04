#include <stdio.h>

using namespace std;

int main(){
    int t,temp,it,mini,index,n1,n2;
    int t_plus[4];
    int t_minus[4];
    int t_temp[4];
    int dane[9001];
    scanf("%d\n", &t);

    for(int i=0;i<t;i++){
        scanf("%d", &dane[i]);
    }
    for(int i=0;i<t;i++){

        temp=dane[i];
        it=0;
        while(temp!=6174 && it<=7){
            int f = temp;
            for(int x=0;x<4;x++){
                t_temp[x] = f%10;
                f = f / 10;
            }
            for(int x=0;x<4;x++){
                mini=-1;
                index=0;
                for(int c=0;c<4;c++){
                    if(t_temp[c]>mini){
                        mini=t_temp[c];
                        index = c;
                    }
                }
                t_plus[x]=mini;
                t_temp[index]=-1;
            }

            t_minus[0] = t_plus[3];
            t_minus[1] = t_plus[2];
            t_minus[2] = t_plus[1];
            t_minus[3] = t_plus[0];
            n1 = t_minus[0] *1000 + t_minus[1] *100 + t_minus[2] *10 + t_minus[3] *1 ;
            n2 = t_plus[0] *1000 + t_plus[1] *100 + t_plus[2] *10 + t_plus[3] *1 ;
            temp = n2-n1;
            it++;
        }
        if(temp!=6174){
            printf("-1 \n");
        }else{
            printf("%d \n", it);
        }
    }

}
