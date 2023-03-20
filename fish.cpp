#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    unsigned int x,res=0;
    scanf("%u",&x);
    unsigned int F[x];
    for(unsigned int i=0;i<x;i++){
        scanf("%u",&F[i]);
    }
    sort(F,F+x);
    for(unsigned int i=0,rnd;i<x;i++){
        bool S=false;
        rnd=F[x-i-1];
        for(unsigned int j=0;j<x;j++){
            if(j==x-i-1){continue;}
            if(rnd<F[j]*2){S=true;break;}
            rnd+=F[j];
        }
        if(!S&&i!=x-1){res++;}
        else{break;}
    }
    printf("%u",res);
    return 0;
}
