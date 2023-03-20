#include<stdio.h>
using namespace std;

int main(){
    int DM,//diameter main
    Ai,//A inner
    Ao,//A outer
    Bi,//B inner 
    Bo;//B outer
    scanf("%d%d%d%d%d",&DM,&Ai,&Ao,&Bi,&Bo);
    if(Ao<=DM){
        if(Bo>DM){
            printf("PIRMO");
        }
    }
    else if(Bo<=DM){
        printf("OTRO");
    }
    else{
        printf("NEVIENU");
    }
    if(Bo<=DM&&Ao<=DM){
        if(Ai>=Bo||Bi>=Ao||DM-Ao>=Bo||DM-Bo>=Ao){
            printf("ABUS");
        }
        else{
            printf("VIENU");
        }
    }
    return 0;
}
