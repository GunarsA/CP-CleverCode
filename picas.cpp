#include<stdio.h>
using namespace std;

int main(){
    int PizzaCount,LeftOvers[3]={},
    Amount[3]={},res=0;
    scanf("%d",&PizzaCount);
    for(int i=0;i<PizzaCount;i++){
        char Temp[3];
        scanf(" %c%c%c",&Temp[0],&Temp[1],&Temp[2]);
        if(Temp[0]=='1'){
            if(Temp[2]=='2'){
                Amount[1]++;
            }
            else{
                Amount[0]++;
            }
        }
        else{
            Amount[2]++;
        }
    }
    res+=Amount[2];
    LeftOvers[0]+=Amount[2];
    res+=Amount[1]/2;
    if(Amount[1]%2){res++;}
    LeftOvers[0]+=(Amount[1]%2)*2;
    if(LeftOvers[0]<Amount[0]){
        res+=(Amount[0]-LeftOvers[0])/4;
        if((Amount[0]-LeftOvers[0])%4){
            res++;
        }
    }
    printf("%d",res);
    return 0;
}