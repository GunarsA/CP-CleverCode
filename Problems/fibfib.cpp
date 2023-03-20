#include<stdio.h>
using namespace std;

int main(){
    int x;
    scanf("%d",&x);
    for(int i=1,LF[]={1,1};i<=x;i++){
        if(i>LF[0]&&i>LF[1]){
            if(LF[0]<LF[1]){
                LF[0]+=LF[1];
            }
            else{
                LF[1]+=LF[0];
            }
        }
        if(i==LF[0]){
            for(int j=i;j>0;j/=10){
                printf("*");
            }
            printf("\n");
        }
        else if(i==LF[1]){
            for(int j=i;j>0;j/=10){
                printf("*");
            }
            printf("\n");
        }
        else{
            printf("%d\n",i);
        }
    }
    return 0;
}