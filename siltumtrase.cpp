#include<iostream>
using namespace std;

int main(){
    int uL,uS,T[12][12]={},L[12][12]={};
    T[0][1]=6;    
    L[0][1]=1;
    cin >> uS >> uL;        
    for(short int x=1;x<=uL;x++){
        for(short int y=1;y<=uS;y++){
            cin >> T[x][y];
            if(T[x][y]==0){T[x][y]=6;}
        }
    }
    for(short int y = 1;y<=uL;y++){
        for(short int x = 1;x<=uS;x++){
            if(((T[y-1][x]==6)||(T[y-1][x]==2)||(T[y-1][x]==4))&&((T[y][x]==6)||(T[y][x]==1)||(T[y][x]==4))){
            L[y][x]+=L[y-1][x];
            }
            if(((T[y][x-1]==6)||(T[y][x-1]==1)||(T[y][x-1]==3))&&((T[y][x]==6)||(T[y][x]==2)||(T[y][x]==3))){
            L[y][x]+=L[y][x-1];
            }
        }
    }
    cout<<L[uL][uS];
    return 0;
}