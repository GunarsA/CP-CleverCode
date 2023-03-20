#include<iostream>
#include<algorithm>
using namespace std;

bool isBigger(string x,string y){
    int tZx=0,tZy=0;
    while(x[tZx]=='0'){tZx++;}
    while(y[tZy]=='0'){tZy++;}
    x.erase(0,tZx);
    y.erase(0,tZy);
    if(y.length()<x.length()){return true;}
    else if(y.length()>x.length()){return false;}
    for(int i=0;i<x.length();i++){
        if(x[i]>y[i]){return true;}
        else if(x[i]<y[i]){return false;}
    }
    return false;
}
bool canRearrangeBigger(string x,string y){
    bool res;
    sort(y.begin(),y.end(),greater<int>());
    isBigger(y,x)?res=true:res=false;
    return res;
}
bool canRearrangeSmaller(string x,string y){
    sort(y.begin(),y.end());
    int tZ=0;
    bool res;
    while(y[tZ]=='0'){tZ++;}
    y.erase(0,tZ);
    while(tZ>0){
        y.insert(1,"0");
        tZ--;
    }
    isBigger(x,y)?res=true:res=false;
    return res;
}
int main(){
    string x,y;
    cin>>x>>y;
    if(isBigger(x,y)){cout<<"IR"<<endl;}
    else{
        cout<<"NAV"<<endl;
        canRearrangeBigger(y,x)?cout<<"IR"<<endl:cout<<"NAV"<<endl;
        canRearrangeSmaller(x,y)?cout<<"IR"<<endl:cout<<"NAV"<<endl;
    }
    return 0;
}