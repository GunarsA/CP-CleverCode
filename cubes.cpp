#include<stdio.h>
using namespace std;

int main(){
    int lenY,lenX,lenZ,MinV=0,MaxV=0;
    scanf("%d%d%d",&lenY,&lenX,&lenZ);
    int CC[lenY]={};//Cube Count
    for(int i=0;i<lenY;i++){
        for(int j=0;j<lenX;j++){
            int F;//Front
            scanf("%d",&F);
            if(F){
                CC[i]++;
            }
        }
        
    }
    for(int i=0;i<lenY;i++){
        int LCC=0;//Level Cube Count
        for(int j=0;j<lenZ;j++){
            int S;//Side
            scanf("%d",&S);
            if(S){
                LCC++;
            }
        }
        //Min Volume
        if(LCC>CC[i]){
            MinV+=LCC;
        }
        else{
            MinV+=CC[i];
        }
        //Max Volume
        MaxV+=(LCC*CC[i]);
    }
    printf("%d %d",MinV,MaxV);
    return 0;
}