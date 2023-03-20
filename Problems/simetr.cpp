#include<iostream>
using namespace std;

bool canMirrorSide(char &x){
    switch(x){ 
        case'A':return true; 
        case'H':return true;  
        case'I':return true;
        case'M':return true;
        case'O':return true;
        case'T':return true;
        case'U':return true;
        case'V':return true;
        case'W':return true;
        case'X':return true; 
        case'Y':return true;
    } 
    return false;
}
bool canMirrorDown(char &x){
    switch(x){ 
        case'B':return true; 
        case'C':return true;  
        case'D':return true;
        case'E':return true;
        case'H':return true;
        case'I':return true;
        case'K':return true;
        case'O':return true;
        case'X':return true;
    } 
    return false;
}
bool canSpin360(char &x){
    switch(x){ 
        case'S':return true; 
        case'H':return true;  
        case'I':return true;
        case'N':return true;
        case'O':return true;
        case'X':return true;
        case'Z':return true;
    } 
    return false;
}
int main(){
    bool Answer=true;
    string S;
    cin>>S;
    int L=S.length();
    //------------------------------------------------------------------------------------------------
    for(int i=0;i<=L/2;i++){
        if((S[i]!=S[(L-1)-i])||(!canMirrorSide(S[i])||!canMirrorSide(S[(L-1)-i]))){Answer=false;break;}
    }
    Answer?cout<<"+":cout<<"-";
    Answer=true;
    //------------------------------------------------------------------------------------------------
    for(int i=0;i<L;i++){
        if(!canMirrorDown(S[i])){Answer=false;break;}
    }
    Answer?cout<<"+":cout<<"-";
    Answer=true;
    //------------------------------------------------------------------------------------------------
    for(int i=0;i<=L/2;i++){
        if((S[i]!=S[(L-1)-i])||(!canSpin360(S[i])||!canSpin360(S[(L-1)-i]))){Answer=false;break;}
    }
    Answer?cout<<"+":cout<<"-";
    return 0;
}