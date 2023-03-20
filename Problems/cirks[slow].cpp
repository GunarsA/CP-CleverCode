#include<stdio.h>
using namespace std;

int gcd(int a,int b){ 
    if(a==0){return b;}  
    return gcd(b%a,a); 
} 
//lcm
int L(int a,int b){
    if(a==0){return b;} 
    else if(b==0){return a;}
    return(a*b)/gcd(a,b); 
} 
int main(){
    int x,rez,pR,D[8]={},kF[8]={};
    scanf("%d",&x);
    rez=x;
    if(x>39){
        kF[4]=(x/11);
        kF[5]=(x/8);
        kF[6]=(x/7);
        kF[7]=(x/6);
    }
    if(x>49){
        kF[3]=(x/15);
        kF[4]=(x/11);
        kF[5]=(x/8);
        kF[6]=(x/7);
        kF[7]=(x/6);
    }
    if(x>59){
        kF[2]=(x/20);
        kF[3]=(x/14);
        kF[4]=(x/11);
        kF[5]=(x/8);
        kF[6]=(x/7);
        kF[7]=(x/6);
    }
    for(D[0]=kF[0];D[0]*2<x;D[0]++){      
        for(D[1]=kF[1];D[1]*2<x-D[0];D[1]++){                   
            for(D[2]=kF[2];D[2]*2<x-D[0]-D[1];D[2]++){                                                 
                for(D[3]=kF[3];D[3]*2<x-D[0]-D[1]-D[2];D[3]++){                                                                  
                    for(D[4]=kF[4];D[4]*2<x-D[0]-D[1]-D[2]-D[3];D[4]++){                                                   
                        for(D[5]=kF[5];D[5]*2<x-D[0]-D[1]-D[2]-D[3]-D[4];D[5]++){                                                                                          
                            for(D[6]=kF[6];D[6]*2<x-D[0]-D[1]-D[2]-D[3]-D[4]-D[5];D[6]++){
                                for(D[7]=kF[7];D[7]*2<x-D[0]-D[1]-D[2]-D[3]-D[4]-D[5]-D[6];D[7]++){
                                    pR=L(L(L(L(L(L(L(L(D[7],D[6]),D[5]),D[4]),D[3]),D[2]),D[1]),D[0]),x-D[0]-D[1]-D[2]-D[3]-D[4]-D[5]-D[6]-D[7]);
                                    if(pR>rez){rez=pR;}
                                }
                            } 
                            if(x<13){break;}                                                                             
                        }
                        if(x<20){break;}                                              
                    }  
                    if(x<32){break;}                                          
                }
                if(x<44){break;}                                                                                                                                                                                                           
            } 
            if(x<61){break;}                          
        }
        if((x!=80)||(D[0]==1)){;break;}
    }
    printf("%d",rez);
    return 0;
}