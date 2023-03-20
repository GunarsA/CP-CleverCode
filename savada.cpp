#include<stdio.h>
using namespace std;

unsigned int digitSum(unsigned int x){
    unsigned int res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}
//Next Element With Given Digit Summ
unsigned int NEWGDS(unsigned int x,unsigned int DS){
    if(digitSum(x)==DS){x++;}
    unsigned int res=x,cDS=digitSum(x);//current Digit Sum
    if(DS>cDS){
        for(unsigned int i=1;DS!=digitSum(res);i*=10){
            if(9-(x%10)<=DS-cDS){res+=(9-(x%10))*i;cDS+=(9-(x%10));x/=10;}
            else{res+=(DS-cDS)*i;}
            while((x==0)&&(DS!=digitSum(res))){
                i*=10;
                if(DS-cDS>9){res+=(9*i);cDS+=9;}
                else{res+=((DS-cDS)*i);}
            }
        }
    }
    else{
        for(unsigned int i=10;DS<digitSum(res);i*=10){
            res-=res%i;
            res+=i;
        }
        if(DS==digitSum(res)){return res;}
        else{return NEWGDS(res,DS);}
    }
    return res;
}
int main(){
    unsigned int element,x;
    scanf("%d%d",&element,&x);
    for(unsigned int i=1;i<x;i++){
        element=NEWGDS(element,digitSum(element*4));
    }
    printf("%d",element);
    return 0;
}