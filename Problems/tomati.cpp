#include<iostream>
using namespace std;

int main(){
    int x,y,z,pK=0,pL=0,rez=1;    
    cin>>x>>y>>z; 
    if(x-y>z){pL=z;}else{pL=x-y;}
    if(y>z){pK=z;}else{pK=y-1;}
    rez+=pL+pK;    
    cout<<rez<<endl;
    return 0; 
}