#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    bool answer=false;
    string x,y;
    cin>>x>>y;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    for(unsigned int i=0,j=0;i<x.length();){
        if(x[i]==y[j]){i++;j++;}
        else{i++;}
        if(j==y.length()){answer=true;break;}
    }
    answer?cout<<"VAR":cout<<"NEVAR";
    return 0;
}