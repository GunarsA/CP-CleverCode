#include<iostream>
using namespace std;
//symbolValue
unsigned int SV(char &x){
    if(x=='I'){return 1;}
    if(x=='V'){return 5;}
    if(x=='X'){return 10;}
    if(x=='L'){return 50;}
    if(x=='C'){return 100;}
    if(x=='D'){return 500;}
    if(x=='M'){return 1000;}
    return 0;
}
unsigned int convert(string &x){
    unsigned int res=0;
    for(unsigned int i=0;i<x.length();i++){
        if(i==x.length()-1){res+=SV(x[i]);break;}
        if(SV(x[i])>=SV(x[i+1])){res+=SV(x[i]);}
        else{res-=SV(x[i]);}
    }
    return res;
}
int main(){
    string x;
    cin>>x;
    cout<<convert(x);
    return 0;
}