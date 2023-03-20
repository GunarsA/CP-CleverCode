#include<stdio.h>
using namespace std;

int main(){
    int x,y,z,S,T,rez;
    scanf("%d%d%d",&x,&y,&z);
    S=((x*z)*2)+((y*z)*2); 
    scanf("%d%d%d",&x,&y,&z);
    T=(x*y)*z;
    rez=S-T;
    if(T>=S){printf("%d%s",rez,"\npietiek");}
    else{printf("%d%s",rez,"\nnepietiek");}
    return 0;
}