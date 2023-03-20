#include<iostream>

using namespace std;


int main(){
    char x[2];
    unsigned short int y[8][8],krd[2];
    cin>>x;
    krd[0]=(x[0]-101);
    krd[1]=(x[1]-61);
    for(unsigned short int i=0;i<8;i++){
        for(unsigned short int j=0;j<8;j++){
            y[i][j]=2;
        }
    }
    for(unsigned short int i=0;i<8;i++){
        y[krd[1]][i]=1;
    }
    for(unsigned short int i=0;i<8;i++){
        y[i][krd[0]]=1;
    }
    for(unsigned short int i=1;i<kdr[0];i++){
        y[kdr[0]-i][krd[1-i]-i]=1;
    }
    for(unsigned short int i=1;i<kdr[0];i++){
        y[kdr[0]-i][krd[1]-i]=1;
    }
    for(unsigned short int i=1;i<kdr[0];i++){
        y[kdr[0]-i][krd[1]-i]=1;
    }
    for(unsigned short int i=1;i<kdr[0];i++){
        y[kdr[0]-i][krd[1]-i]=1;
    }



    for(unsigned short int i=0;i<8;i++){
        for(unsigned short int j=0;j<8;j++){
            cout<<y[i][j];
        }
        cout<<endl;
    }


    return 0;
}