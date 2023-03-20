#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    unsigned int M,N;
    scanf("%u%u",&M,&N);
    string S;
    bool polinom[M]={};
    unsigned int *res=new unsigned int[N+2]();
    cin>>S;
    for(unsigned int i=0;i<(M+1)/2;i++){
        if(S[i]==S[M-1-i]){polinom[i]=true;polinom[M-1-i]=true;res[0]++;}
    }
    for(unsigned int i=0,a,b,rnd;i<N;i++){
        scanf("%u%u",&a,&b);
        swap(S[a-1],S[b-1]);
        rnd=polinom[a-1]+polinom[b-1];

        if(S[a-1]==S[M-a]){
            polinom[a-1]=true;
            polinom[M-a]=true;
        }   
        else{
            polinom[a-1]=false;
            polinom[M-a]=false;
        }
        if(S[b-1]==S[M-b]){
            polinom[b-1]=true;
            polinom[M-b]=true;
        }   
        else{
            polinom[b-1]=false;
            polinom[M-b]=false;
        }   
        res[i+1]=res[i]-(rnd-(polinom[a-1]+polinom[b-1]));
    }
    for(unsigned int i=1;i<=N;i++){
        printf("%u\n",res[i]);
    }
    return 0;
}