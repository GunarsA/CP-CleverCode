#include<stdio.h>
using namespace std;

int main(){
    unsigned int x,y,maz=250000;
    double rez,atl=0;
    scanf("%d%d",&x,&y);
    unsigned int z[x];
    for(unsigned int i=0;i<x;i++){
        scanf("%d",&z[i]);
        if(z[i]<maz){maz=z[i];}
    }
    rez=(maz/y);
    for(unsigned int i=0;i<x;i++){
        atl+=(z[i]-(rez*y));
    }
    printf("%.0f%c%.0f",rez,' ',atl);
    return 0;
}