#include<stdio.h>
using namespace std;

int countOccurrences(int x,int D){
    int res=0,T=x;//temporary
    for(int digPow=1;T>0;T/=10,digPow*=10){
        res+=(T/10)*digPow;
        if(!D){res-=digPow;}
        if(T%10>=D){
            if(T%10>D){res+=digPow;}
            else{res+=(x%digPow)+1;}
        }
    }
    return res;
}
int main(){
    int first,last,x;
    scanf("%d%d%d",&first,&last,&x);
    for(int digit=9,sum=0;digit>=0;digit--){
        sum+=countOccurrences(last,digit)-countOccurrences(first-1,digit);
        if(sum>=x){printf("%d",digit);break;}
        else if(!digit){printf("NAV");}
    }
    return 0;
}