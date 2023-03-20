#include<stdio.h>
#include<string>
#include<vector>
#define GC getchar
#define PC putchar
#define M 1000000000
using namespace std;

void scanInt(int &x){
    register int c=GC();
    bool negatve=0;
    x=0;
    for(;(c<48||c>57);c=GC());
    if(c=='-'){
        negatve=1;
        c=GC();
    }
    for(;c>47&&c<58;c=GC()){
        x=(x<<1)+(x<<3)+c-48;
    }
    if(negatve){
        x=-x;
    }
}
inline void writeInt(int x){
    string xS=to_string(x);
    for(auto i:xS){
        PC(i);
    }
}
int main(){
    int lenY,lenX,CutOut;
    scanInt(lenY);
    scanInt(lenX);
    scanInt(CutOut);
    vector< vector<int> > Matrix(lenY+1,vector<int>(lenX+1,0));
    Matrix[1][1]=1;
    for(int i=0,tmpY,tmpX;i<CutOut;++i){
        scanInt(tmpY);
        scanInt(tmpX);
        Matrix[tmpY][tmpX]=-1;
    }
    for(int i=1;i<=lenY;i++){
        for(int j=1;j<=lenX;j++){
            if((Matrix[i][j]!=-1)&&(Matrix[i-1][j]!=-1)){
                Matrix[i][j]+=Matrix[i-1][j];
            }
            if((Matrix[i][j]!=-1)&&(Matrix[i][j-1]!=-1)){
                Matrix[i][j]+=Matrix[i][j-1];
            }
            if(Matrix[i][j]>=M){
                Matrix[i][j]%=M;
            }
        }
    }
    writeInt(Matrix[lenY][lenX]);
    return 0;
}