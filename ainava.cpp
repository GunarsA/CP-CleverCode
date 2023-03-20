#include<stdio.h>
using namespace std;

int main(){
    int HouseCount,LandScape=0;
    scanf("%d",&HouseCount);
    int Houses[HouseCount];
    for(int i=0;i<HouseCount;i++){
        scanf("%d",&Houses[i]);
    }
    for(int i=1;i<HouseCount;LandScape+=2,i++){
        int Largest=Houses[i-1];
        for(int l=i-2;l>=0;l--){
            if(Houses[l]>Largest){
                LandScape++;
                Largest=Houses[l];
            }
        }
        Largest=Houses[i];
        for(int r=i+1;r<HouseCount;r++){
            if(Houses[r]>Largest){
                LandScape++;
                Largest=Houses[r];
            }
        }
    }
    printf("%d",LandScape);
    return 0;
}