#include<stdio.h>

using namespace std;
struct Barrel{
    int Size;
    float Value;
};


int main(){
    int BarrelCount,OperationCount;
    scanf("%d%d",&BarrelCount,&OperationCount);
    Barrel Barrels[BarrelCount]={};
    for(int i=0;i<BarrelCount;i++){
        scanf("%d",&Barrels[i]);
    }
    for(int i=0;i<OperationCount;i++){

    }

    return 0;
}