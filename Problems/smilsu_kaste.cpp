#include<stdio.h>
#include<iostream>
using namespace std;

char matrix[1000][1000];

int findNumber(int locY,int locX){
    if(matrix[locY][locX+1]=='#'){
        if(matrix[locY][locX+2]=='#'){
            if(matrix[locY+1][locX]=='#'){
                if(matrix[locY+1][locX+2]=='#'){
                    if(matrix[locY+3][locX]=='#'){
                        if(matrix[locY+2][locX+1]=='#'){
                            return 8; 
                        }
                        else{
                            return 0;
                        }
                         
                    }
                    else{
                        return 9;
                    }
                }
                else{
                    if(matrix[locY+3][locX]=='#'){
                        return 6;
                    }
                    else{
                        return 5;
                    }
                }
            }
            else{
               if(matrix[locY+2][locX]=='#'){
                   if(matrix[locY+3][locX]=='#'){
                       return 2;
                   }
                   else{
                       return 3;
                   }
               }
               else{
                   return 7;
               }
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 4;
    }
}
int main(){
    int size;
    scanf("%d ",&size);
    for(int i=0;i<size;i++){
            cin>>matrix[i];
    }
    bool FDC=0,SDC=0,Stop=0;//First Digit Count, Second Digits Count
    int locY,locX;
    for(int lenY=0;lenY<size;lenY++){
        for(int lenX=0;lenX<size;lenX++){
            if(matrix[lenY][lenX]=='#'){
                locY=lenY;locX=lenX;
                if(matrix[lenY][lenX+4]=='#'){
                    FDC=true;
                    if(matrix[lenY][lenX+4+8+4]=='#'){
                        SDC=true;
                    }
                }
                else if(matrix[lenY][lenX+8+4]=='#'){
                    SDC=true;
                }
                Stop=1;
                break;
            }
        }
        if(Stop){break;}
    }
    bool add=false;
    int FirstN=findNumber(locY,locX),SecondN;
    if(FDC==true){
        if(matrix[locY+1][locX+4+5]=='#'){
            add=true;
        }
        FirstN*=10;
        FirstN+=findNumber(locY,locX+4);
        SecondN=findNumber(locY,locX+4+8);
        if(SDC==true){  
            SecondN*=10;
            SecondN+=findNumber(locY,locX+4+8+4);
        }
    }
    else{
        if(matrix[locY+1][locX+5]=='#'){
            add=true;
        }
        SecondN=findNumber(locY,locX+8);
        if(SDC==true){
            SecondN*=10;
            SecondN+=findNumber(locY,locX+8+4);
        }
    }
    /*
    cout<<"1 - "<<FirstN<<" 2 - "<<SecondN<<" FDC - "<<FDC<<" SDC - "<<SDC<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            cout<<matrix[locY+i][locX+j];
        }
        cout<<endl;
    }
    */
    add?
    printf("%d",FirstN+SecondN):
    printf("%d",FirstN-SecondN);
    return 0;
}
