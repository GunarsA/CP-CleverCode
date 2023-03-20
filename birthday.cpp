#include<iostream>
using namespace std;

int main(){
    unsigned short int x;
    cin>>x;
    for(unsigned short int i=1;i<x*2;i++){
        if((i%2)==1){cout<<"$";}
        else{cout<<" ";}
    }
    cout<<endl;
    for(unsigned short int i=1;i<x*2;i++){
        if((i%2)==1){cout<<"|";}
        else{cout<<" ";}
    }
    cout<<endl;
    for(unsigned short int i=1;i<x*2;i++){
        cout<<"-";
    }
    cout<<endl;
    for(unsigned short int i=1;i<x*2;i++){
        cout<<"~";
    }
    cout<<endl;
    for(unsigned short int i=1;i<x*2;i++){
        cout<<"-";
    }
    return 0;
}