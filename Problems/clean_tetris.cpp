#include<stdio.h>
using namespace std;

int main(){
    int lenY,lenX,CC;
    scanf("%d%d",&lenY,&lenX);
    CC=lenY;
    char tetris[lenY][lenX];
    bool clear[lenY]={};
    for(int i=0;i<lenY;i++){
        scanf("%s",&tetris[i][0]);
        for(int j=0;j<lenX;j++){
            if(tetris[i][j]=='0'){
                clear[i]=true;
                CC--;
                break;
            }
        }
    }
    for(int i=0;i<lenY;){
        if(CC>0){
            for(int j=0;j<lenX;j++){
                printf("0");
            }
            printf("\n");
            CC--;
        }
        else{
            if(clear[i]){
                for(int j=0;j<lenX;j++){
                    printf("%c",tetris[i][j]);
                }
                printf("\n");
            }
            i++;
        }
    }
    return 0;
}