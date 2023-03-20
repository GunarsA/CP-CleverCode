#include<stdio.h>
using namespace std;

int main(){ 
    unsigned int count; 
    unsigned long long int a,b,c,d,e; 
    scanf("%u",&count);
    bool atbildes[count];
    for(int i=0;i<count;i++){
        scanf("%llu%llu%llu%llu%llu",&a,&b,&c,&d,&e);
        long long int res=(a*1);
        res+=(b*-1);
        res+=(c*2);
        res+=(d*-2);
        res+=(e*0);
        if(res==0){atbildes[i]=true;}
        else{atbildes[i]=false;}
        if(a+b!=2){atbildes[i]=false;}
    }
    for(int i=0;i<count;i++){
        if(atbildes[i]==true){printf("Alohomora\n");}
        else{printf("Avada Kedavra\n");}
    }
    return 0;
}