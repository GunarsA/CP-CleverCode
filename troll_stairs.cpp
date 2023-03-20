#include<stdio.h>
using namespace std;

int main(){
    int StepCount,MaxHeight;
    bool Can=true;
    scanf("%d%d",&StepCount,&MaxHeight);
    for(int i=0,Step,PStep;i<StepCount;i++,PStep=Step){
        scanf("%d",&Step);
        if(Step-PStep>MaxHeight&&i!=0){Can=false;}
    }
    Can?
    printf("Yey!"):
    printf("Oh, NO!");
    return 0;
}