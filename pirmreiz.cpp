#include<stdio.h> 
#include<cmath>
using namespace std;

void printUniquePrimeFactors(int &x) { 
    if(x%2==0){
        x/=2;
        printf("%d\n",2); 
        while(x%2==0){x/=2;} 
    } 
    for(int i=3;i*i<=x;i+=2){ 
        if(x%i==0){
            x/=i;
            printf("%d\n",i);
            while(x%i==0){x/=i;} 
        }
    } 
    if(x>1){printf("%d\n",x);}
} 
int main(){ 
    int x;
    scanf("%d",&x); 
    printUniquePrimeFactors(x); 
    return 0; 
} 