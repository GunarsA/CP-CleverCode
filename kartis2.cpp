#include<stdio.h>
using namespace std;

int main(){
    int x;
    scanf("%d",&x);
    bool C[x]={},q=false;//checked
    for(int i=0,j=0,k=1;j<x;i++){
        if(i>=x){k*=2;i=1;}
        if(!C[i]){
            if(!q){printf("%d ",i+1);j++;C[i]=true;i+=(k-1);q=true;}
            else{q=false;}
        }
    }
    return 0;
}