#include<stdio.h>
using namespace std;

int strLen(int &x){
    int res=0;
    for(int i=1;i<=x;i*=10){
        res+=(x-i+1);
    }
    return res;
}
int firstOccurrence(int &x){
    int res=1,len=1,lenP=1;//length Power
    while((lenP*10)<=x){lenP*=10;len++;}
    for(int i=1,j=10,Str=0;;i++){
        if(i==x){return strLen(x)-(len-1);}
        if(i%j==0){j*=10;}
        Str*=j;Str+=i;
        for(int k=j/10;k>0;k/=10,res++){
            if(Str/k==x){return res-(len-1);}
            Str%=(lenP*k);
        }
    }
}
int main(){
    int x;
    scanf("%d",&x);
    printf("%d",firstOccurrence(x));
    return 0;
}