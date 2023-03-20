#include<stdio.h>
#include<string>
#include<algorithm>
#define GC getchar_unlocked
#define PC putchar_unlocked
using namespace std;

string ET[1000][1000];//Excel Table
//----------------------------------------------------------------------------
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
//----------------------------------------------------------------------------
void scanString(string &x){
    register int c=GC();
    x.clear();
    for(;(c<41||c>126);c=GC());
    for(;c>41&&c<126;c=GC()){
        x.push_back(c);
    }
}
//----------------------------------------------------------------------------
inline void writeInt(int x){
    string xS=to_string(x);
    for(auto i:xS){
        PC(i);
    }
}
//----------------------------------------------------------------------------
inline void writeString(string &x){
    for(auto i:x){
        PC(i);
    }
}
//----------------------------------------------------------------------------
string sum(string &Long,string &Short){
    string res;
    int lenL=Long.length()-1,lenS=Short.length()-1;
    bool rem=false,Swap=false;
    //---- "Long" has to be longer than "Short" ----
    if(Short.length()>Long.length()){
        swap(Long,Short);
        lenL=Long.length()-1;
        lenS=Short.length()-1;
        Swap=true;
    }
    for(int i=0;i<=lenL+1;i++){
        if(lenS>=i){//Add both
            res.push_back(Short[lenS-i]+Long[lenL-i]-'0');
            if(rem){res[i]++;rem=false;}
        }
        else if(lenL>=i){//Add longest
            res.push_back(Long[lenL-i]);
            if(rem){res[i]++;rem=false;}
        }
        else if(rem){//Add remainder
            res.push_back('1');
            rem=false;
        }
        if(res[i]>57){//Remove overflow
            res[i]-=10;
            rem=true;   
        }   
    }
    //-- Swap variables back if needed --
    if(Swap){
        swap(Long,Short);
    }
    reverse(res.begin(),res.end());
    return res;
}
//----------------------------------------------------------------------------
string& fillElement(int &lenY,int &lenX,bool Checked[][1000]){
    if(ET[lenY][lenX][0]>47&&ET[lenY][lenX][0]<58){
        return ET[lenY][lenX];//Return if number is found
    }
    else if(Checked[lenY][lenX]==true){
        ET[lenY][lenX]="error";
        return ET[lenY][lenX];//Break if Dead End is reached (Loop)
    }
    //-------------- Find next location/s ----------------
    int locY=0,locX=0,locYA=0,locXA=0;
    bool Add=false;
    for(unsigned int i=0;ET[lenY][lenX].length()>i;i++){
        //English alphabet is base 26 numeric system
        if(ET[lenY][lenX][i]>64
        &&ET[lenY][lenX][i]<91){
            locX*=26;//Column
            locX+=ET[lenY][lenX][i]-64;
        }
        else if(ET[lenY][lenX][i]!='+'){
            locY*=10;//Row
            locY+=ET[lenY][lenX][i]-48;
        }
        //Second locations found (Add function needed)
        else{
            i++;Add=true;
            for(;ET[lenY][lenX].length()>i;i++){
                if(ET[lenY][lenX][i]>64
                &&ET[lenY][lenX][i]<91){
                    locXA*=26;
                    locXA+=ET[lenY][lenX][i]-64;
                }
                else{
                    locYA*=10;
                    locYA+=ET[lenY][lenX][i]-48;
                }
            }
        }
    }
    //----- Find next element/s value/s recursively ------
    Checked[lenY][lenX]=true;
    if(!Add){
        ET[lenY][lenX]=fillElement(--locY,--locX,Checked);
    }
    else{
        string add1=fillElement(--locY,--locX,Checked),
        add2=fillElement(--locYA,--locXA,Checked);
        //--- Check if there is unobtainable value ---
        if(add1=="error"||add2=="error"){
            ET[lenY][lenX]="error";
        }
        else{
            ET[lenY][lenX]=sum(add1,add2);
        }
    }
    return ET[lenY][lenX];
}
//----------------------------------------------------------------------------
bool fillTable(int &lenY,int &lenX){
    bool Checked[1000][1000]={};
    for(int i=0;i<lenY;i++){
        for(int j=0;j<lenX;j++){
            if(fillElement(i,j,Checked)=="error"){
                return false;
            }
        }
    }
    return true;
}
//----------------------------------------------------------------------------
int main(){
    int TableCount;
    scanInt(TableCount);
    for(int i=0,lenY,lenX;i<TableCount;i++){
        scanInt(lenY);
        scanInt(lenX);
        for(int j=0;j<lenY;j++){
            for(int k=0;k<lenX;k++){
                 scanString(ET[j][k]);
            }
        }
        if(fillTable(lenY,lenX)){
            for(int j=0;j<lenY;j++){
                for(int k=0;k<lenX;k++){
                    writeString(ET[j][k]);
                    printf(" ");
                }
                printf("\n");
            }
        }
        else{
            printf("Filmas beigas.\n");
        }
    }
    return 0;
}