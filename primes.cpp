#include<stdio.h>
using namespace std;

bool isPrime(unsigned int &x){
  for(unsigned int y=2;y*y<=x;y++){
    if(x%y==0){
        return false;
      }
  }
  return true;
}
unsigned int primeCount(unsigned int x){
    unsigned int res=0;
    bool *notPrime=new bool[x]();
    if(x<4){
        if(x==3){return 2;}
        if(x==2){return 1;}
        if((x==1)||(x==0)){return 0;}
    }
    for(unsigned int i=2;i*i<=x;i++){
        if(isPrime(i)){
            for(unsigned int j=i*i;j<=x;j+=i){
                notPrime[j-1]=true;
            }
        }
    }
    for(unsigned int i=1;i<x;i++){
        if(notPrime[i]==false){res++;}
    }
    return res;
}
int main(){
    unsigned int a,b,res;
    scanf("%u%u",&a,&b);
    res=primeCount(b)-primeCount(a-1);
    printf("%u",res);
    return 0;
}