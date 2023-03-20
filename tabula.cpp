#include<stdio.h>
using namespace std;

long long int GCD(long long int a,long long int b){ 
    if(b==0){return a;}
    return GCD(b,a%b);     
} 
int main(){
    long long int lenY,lenX;
    scanf("%lld%lld",&lenY,&lenX);
    if(lenY==1){
        printf("%lld",lenX);
    }
    else if(lenX==1){
        printf("%lld",lenY);
    }
    else if(lenY==lenX){
        printf("%lld",lenY);
    }
    else{
        printf("%lld",GCD(lenY-1,lenX-1)+1);
    }
    return 0;
}