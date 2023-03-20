#include<stdio.h>
using namespace std;

int main(){
    int TL;//Train length
    scanf("%d",&TL);
    int MP[TL+1][4]={},//Max Passegers
    CS[TL+1]={},//Carrige Sum
    MLL;//MiniLoko max Length
    for(int i=1;i<=TL;i++) {
        scanf("%d",&CS[i]);
        CS[i]+=CS[i-1];
    }
    scanf("%d",&MLL);
    for(int i=MLL;i<=TL;i++){
        for(int j=1;j<=3;j++){
        MP[i][j]=MP[i-1][j];
        if(MP[i][j]<MP[i-MLL][j-1]+(CS[i]-CS[i-MLL]))
            MP[i][j]=MP[i-MLL][j-1]+(CS[i]-CS[i-MLL]);
        }
    }
    if(MLL>TL){MP[TL][3]=CS[TL];}
    printf("%d",MP[TL][3]);
}