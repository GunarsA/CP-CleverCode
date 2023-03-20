#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

struct Path{
    short int X;
    short int Y;
    bool M[6][6];
};
int main(){
    string Word;
    cin>>Word;
    short int lenY,lenX;
    Path TEMP={};
    scanf("%hu%hu%hu%hu",&lenY,&lenX,&TEMP.Y,&TEMP.X);
    TEMP.Y--;TEMP.X--;
    TEMP.M[TEMP.Y][TEMP.X]=true;
    queue<Path> Route;
    Route.push(TEMP);
    char Matrix[lenY][lenX];
    for(int i=0;i<lenY;i++){
        scanf(" %s",&Matrix[i][0]);
    }
    if(Matrix[TEMP.Y][TEMP.X]!=Word[0]
    ||Word.length()>(lenY*lenX)){
        printf("0");
        return 0;
    }
    for(int i=1,RC=Route.size();i<Word.length();i++,RC=Route.size()){
        for(int j=0,locX,locY;j<RC;j++){
            locX=Route.front().X,locY=Route.front().Y;
            if(Matrix[locY][locX+1]==Word[i]
            &&!Route.front().M[locY][locX+1]
            &&locX+1<lenX){
                Route.front().M[locY][locX+1]=true;
                Route.front().X++;
                Route.push(Route.front());
                Route.front().X--;
                Route.front().M[locY][locX+1]=false;
            }
            if(Matrix[locY+1][locX]==Word[i]
            &&!Route.front().M[locY+1][locX]
            &&locY+1<lenY){
                Route.front().M[locY+1][locX]=true;
                Route.front().Y++;
                Route.push(Route.front());
                Route.front().Y--;
                Route.front().M[locY+1][locX]=false;
            }
            if(Matrix[locY][locX-1]==Word[i]
            &&!Route.front().M[locY][locX-1]
            &&locX>0){
                Route.front().M[locY][locX-1]=true;
                Route.front().X--;
                Route.push(Route.front());
                Route.front().X++;
                Route.front().M[locY][locX-1]=false;
            }
            if(Matrix[locY-1][locX]==Word[i]
            &&!Route.front().M[locY-1][locX]
            &&locY>0){
                Route.front().M[locY-1][locX]=true;
                Route.front().Y--;
                Route.push(Route.front());
                Route.front().Y++;
                Route.front().M[locY-1][locX]=false;
            }
            Route.pop();
        }
    }
    printf("%d",Route.size());
    return 0;
}