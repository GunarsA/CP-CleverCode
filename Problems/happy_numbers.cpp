#include<stdio.h>
using namespace std;

int squareSigitSum(int &x){
    x*=x;
    int res=0;
    while(x>0){
        res+=(x%10);
        x/=10;
    }
    x=res;
    return res;
}
int main(){
    int C,res=0;
    scanf("%d",&C);
    for(int i=0,T;i<C;i++){
        scanf(" %d",&T);
        if(squareSigitSum(T)==1){res++;}
        else if(squareSigitSum(T)==1){res++;}
        else if(squareSigitSum(T)==1){res++;}
        else if(squareSigitSum(T)==1){res++;}
    }
    printf("%d",res);
    return 0;
}