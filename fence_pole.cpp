#include<stdio.h>
using namespace std;

int maxValue(int Len,int Values[],int sPos,int maxD){
    bool S2=false,S3=false,S4=false;
    for(int maxV=Values[sPos-1],curV=Values[sPos-1],R=1,L=1;;){
        //-----------------------------------------
        if(!S2&&(sPos+R<=Len&&R<=maxD)){
            curV+=Values[(sPos-1)+R++];
            if(curV>maxV){
                maxV=curV;
            }
        }
        //-----------------------------------------
        else if(!S2){
            S2=true;
            R--;
        }
        else if(!S3&&(R!=0)){
            while(L+(R*2)<=maxD&&sPos-L>0){
                curV+=Values[(sPos-1)-L++];
                if(curV>maxV){
                    maxV=curV;
                }
            }
            curV-=Values[(sPos-1)+R--];
        }
        //-----------------------------------------
        else if(!S3){
            S3=true;
        }
        else if(!S4&&(sPos-L>0&&L<=maxD)){
            curV+=Values[(sPos-1)-L++];
            if(curV>maxV){
                maxV=curV;
            }
        }
        //-----------------------------------------
        else if(!S4){
            S4=true;
            L--;
            R++;
        }
        else if(L!=0){
            while(R+(L*2)<=maxD&&(sPos-1)+R<Len){
                curV+=Values[(sPos-1)+R++];
                if(curV>maxV){
                    maxV=curV;
                }
            }
            curV-=Values[(sPos-1)-L--];
        }
        //-----------------------------------------
        else{
            return maxV;
        }
    }
}
int main(){
    int poleC,startPole,maxDistance;
    scanf("%d%d%d",&poleC,&startPole,&maxDistance);
    int poleValue[poleC];
    for(int i=0;i<poleC;i++){
        scanf("%d",&poleValue[i]);
    }
    printf("%d",maxValue(poleC,poleValue,startPole,maxDistance));
    return 0;
}