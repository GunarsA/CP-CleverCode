#include<stdio.h>
using namespace std;

int digitSum(int x){
    int res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    int x;
    scanf("%d",&x);
    for(int R1=1,R2=3,R3=9;;x+=digitSum(x)){
        while(x>R1){R1+=digitSum(R1);}
        while(x>R2){R2+=digitSum(R2);}
        while(x>R3){R3+=digitSum(R3);}
        if(x==R1){printf("1 %d",x);break;}
        if(x==R2){printf("3 %d",x);break;}
        if(x==R3){printf("9 %d",x);break;}
    }
    return 0;
}