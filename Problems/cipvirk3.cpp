#include<stdio.h>
using namespace std;

unsigned long long int strLen(unsigned long long int &x){
    unsigned long long int res=0;
    for(unsigned long long int i=1;i<=x;i*=10){
        res+=(x-i+1);
    }
    return res;
}
int main(){
  unsigned long long int x;
  scanf("%llu",&x);
  printf("%llu",strLen(x));
  return 0;
}