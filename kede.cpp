#include<stdio.h>
using namespace std;

int main(){
    int res=0,
    C,//Count
    anyC=0,//any count
    quant[9999]={};
    scanf("%d",&C);
    for(int i=0,j;i<C;i++){
        scanf("%d",&j);
        if(j!=1){anyC++;}
        if(j<10000){quant[j-1]++;}
    }
    for(int i=1;i<9999&&anyC>quant[0]+2;i++){
        while(quant[i]>0&&anyC>quant[0]+2){
            int j=quant[i];
            while(j>0&&anyC>quant[0]+2){
                quant[0]++;j--;
            }
            if(j>0){break;}
            anyC--;quant[i]--;
        }
    }
    if(anyC>0){anyC--;res++;}
    else{quant[0]--;res++;}
    for(int i=0;i<C;i++){
        if(quant[0]>0&&anyC>0){res++;anyC--;quant[0]--;}
        else if(quant[0]==0){res+=anyC-1;break;}
        else if(anyC==0){res+=(quant[0]-1)/2;break;}
    }
    printf("%d",res);
    return 0;
}