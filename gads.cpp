#include<stdio.h>
using namespace std;

int digitSum(unsigned long long int x){
    int res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    unsigned long long int x,i;
    bool A=false;
    scanf("%llu",&x);
    if(x>162){i=x-162;}
    else{i=0;}
    while(i<x){
        if((x-i)==digitSum(i)){printf("%llu ",i);A=true;}
        i++;
    }
    if(!A){printf("NAV");}
    return 0;
}