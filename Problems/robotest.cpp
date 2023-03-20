#include<iostream>
using namespace std;

int main(){
    int size,yLoc=0,xLoc=0;
    string path;
    cin>>size;
    bool mars[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            char input;
            cin>>input;
            input=='+'?
            mars[i][j]=true:
            mars[i][j]=false;
        }
    }
    cin>>path;
    for(int i=0;i<path.length();i++){
        if(path[i]=='T'){
            if(mars[yLoc-1][xLoc]&&yLoc>0){
                yLoc--;
            }
        }
        else if(path[i]=='B'){
            if(mars[yLoc+1][xLoc]&&yLoc<size-1){
                yLoc++;
            }
        }
        else if(path[i]=='R'){
            if(mars[yLoc][xLoc+1]&&xLoc<size-1){
                xLoc++;
            }
        }
        else{
            if(mars[yLoc][xLoc-1]&&xLoc>0){
                xLoc--;
            }
        }
    }
    if(yLoc==size-1&&xLoc==size-1){
        cout<<"0";
    }
    else{
        cout<<"1"<<endl<<xLoc<<" "<<yLoc;
    }
    return 0;
}