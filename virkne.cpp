#include<stdio.h>
using namespace std;

int gcd(int a,int b){
    if(a==0){return b;}
    return gcd(b%a,a);
}
int lcm(int a,int b){
    if(a==0){return b;}
    if(b==0){return a;}
    return (a*b)/gcd(a,b);
}
int main (){
    int Divsors[3],x,elementCount,res=0;
    scanf("%d%d%d%d",&Divsors[0],&Divsors[1],&Divsors[2],&x);
    int Interval=elementCount=lcm(Divsors[0],lcm(Divsors[1],Divsors[2]));
    bool String[Interval]={};
    for(int i=0;i<3;i++){
        for(int j=Divsors[i];j<=Interval;j+=Divsors[i]){
	        if(!String[j-1]){
                elementCount--;
                String[j-1]=1;
            }
	    }
    }
    res=((x/elementCount)*Interval)-1;
    for(int i=0;i<x%elementCount;res++){
        if(((res+1)%Divsors[0]!=0)&&((res+1)%Divsors[1]!=0)&&((res+1)%Divsors[2]!=0)){
            i++;
        }
    }
    printf("%d",res);
    return 0;
}