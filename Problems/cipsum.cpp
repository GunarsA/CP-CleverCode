#include<stdio.h>
using namespace std;

long long int digitSum(long long int &x){
    int res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    long long int x;
    scanf("%lld",&x);
    printf("%d",digitSum(x));
    return 0;
}