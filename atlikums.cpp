#include<iostream>
#include<string>
using namespace std;

unsigned int mod(string &num,unsigned int &x){ 
    unsigned int res=0; 
    for(unsigned int i=0;i<num.length();i++){
         res=(res*10+num[i]-'0')%x;
    }
    return res;
}
int main(){
    unsigned int y;
    string x;
    cin>>x;
    cin>>y;
    cout<<mod(x,y)<<endl;
    return 0;
}