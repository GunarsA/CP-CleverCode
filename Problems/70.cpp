#include<iostream>
#include<string>
using namespace std;

bool mod(string &num,unsigned int &x){ 
    unsigned int res=0; 
    for(unsigned int i=0;i<num.length();i++){
         res=(res*10+num[i]-'0')%x;
    }
    if(res==0){return true;}      
    else{return false;} 
} 
int main(){
    unsigned int x;
    string res="7";
    cin>>x;
    for(unsigned int i=1;;i++){
        if(i%100==1){for(char i=0;i<100;i++){res+='0';}}
        if(mod(res,x)){break;}
        res[i]='7';
    }
    for(unsigned int i=res.length();i>0;i--){
        char e;
        if(res[i]=='0'){e='0';}else{e='7';}
        res.erase(i,1);           
        if(!mod(res,x)){res+=e;break;}     
    }
    cout<<res<<endl;
    return 0;
}