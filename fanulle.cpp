#include<stdio.h>
using namespace std;

int trailZeros(int n) { 
    int res=0; 
    for(int i=5;n/i>=1;i*=5){ 
        res+=n/i; 
    }
    return res; 
} 
int main(){
    int F;
    scanf("%d",&F);
    printf("%d",trailZeros(F));
    return 0;
}