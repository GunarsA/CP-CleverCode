#include<stdio.h>
using namespace std;

long long int divisorSumTo(long long int &x){
    long long int res=x,kF=0;
    for(long long int i=1;i*i<=x;i++){
        res+=(((x/i)*((x/i)+1))/2)-1;
        kF=i;
    }
    for(long long int i=2;(x/i)-kF>0;i++){  
        res+=(((x/i)-kF)*i); 
    }
    return res;
}
int main(){
    long long int a,b;
    scanf("%lld%lld",&a,&b);
    printf("%lld",divisorSumTo(b)-divisorSumTo(--a));
    return 0;
}