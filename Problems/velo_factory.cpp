#include<stdio.h>
using namespace std;

long long int numLen(long long int Number){
    long long int res=0;
    while(Number>0){
        Number/=10;
        res++;
    }
    return res;
}
bool isPrime(long long int x){
    for(long long int y=2;y*y<=x;y++){
        if(x%y==0){
            return false;
        }
    }
    return true;
}
long long int OctToDec(long long int &Oct){
    long long int res=0,len=numLen(Oct);
    for(long long int B=10;len>0;len--,B*=10){
        res*=8;
        long long int digit=Oct;
        while(digit>=B){
            digit/=10;
        }
        res+=digit%10;
    }
    return res;
}
int DFB(long long int Num,long long int Dig){
    long long int res=0;
    for(long long int i=0;i<Dig;i++){
        res=Num%10;
        Num/=10;
    }
    return res;
}
int main(){
    long long int oct;
    scanf("%lld",&oct);
    for(long long int i=oct+1,j=1;DFB(i,numLen(oct))<8;i+=j){
        while(DFB(i,numLen(j))>7){
            j*=10;
            i=oct+j;
        }
        if(numLen(i)!=numLen(oct)){
            break;
        }
        if(isPrime(OctToDec(i))){
            printf("%lld\n",i);
            oct=i;
            j=1;
        }
    }
    return 0;
}