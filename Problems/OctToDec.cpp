#include<stdio.h>
using namespace std;

int numLen(int Number){
 int res=0;
 while(Number>0){
    Number/=10;
    res++;
 }
 return res;
}
int OctToDec(int &Oct){
    int res=0,len=numLen(Oct);
    for(int B=10;len>0;len--,B*=10){
        res*=8;
        int digit=Oct;
        while(digit>=B){
            digit/=10;
        }
        res+=digit%10;
    }
    return res;
}
int main(){
    int x;
    scanf("%d",&x);
    printf("%d",OctToDec(x));
    return 0;
}