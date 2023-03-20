#include<stdio.h>
using namespace std;

int main(){
    unsigned int x,res;
    scanf("%u",&x);
    res=1+(x-2)*2;
    if(x==1){res=0;}
    printf("%u",res);
    return 0;
}