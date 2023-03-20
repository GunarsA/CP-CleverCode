#include<stdio.h>

using namespace std;

int main(){
    int Len,Operations;
    scanf("%d%d",&Len,&Operations);
    int Map[Len]={};
    for(int i=0,Loc;i<Operations;i++){
        scanf("%d",&Loc);
        Map[--Loc]=(i%2)+1;
        for(int l=1;Loc-l>=0&&Map[Loc-l]!=0;l++){
            if(Map[Loc-l]==(i%2)+1){
                l--;
                while(l>0){
                    Map[Loc-l--]=0;
                }
                break;
            }
        }
        for(int r=1;Loc+r<Len&&Map[Loc+r]!=0;r++){
            if(Map[Loc+r]==(i%2)+1){
                r--;
                while(r>0){
                    Map[Loc+r--]=0;
                }
                break;
            }
        }
    }
    int WhiteCount=0,BlackCount=0;
    for(int i=0;i<Len;i++){
        if(Map[i]==1){WhiteCount++;}
        else if(Map[i]==2){BlackCount++;}
    }
    printf("%d %d",WhiteCount,BlackCount);
    return 0;
}