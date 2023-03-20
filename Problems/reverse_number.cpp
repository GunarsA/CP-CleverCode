#include<iostream>
#include<string>
using namespace std;

string reverseSum(string &x,string &y){
    string rez;
    bool atl=false;
    for(int i=1;i<=(x.length()+1)||(i<=y.length()+1);i++){
        if((y.length()>=i)&&(x.length()>=i)){
            rez.push_back((y[i-1]+x[i-1])-'0');
            if(atl){rez[i-1]+=1;atl=false;}
        }
        else if(x.length()>=i){
            rez.push_back(x[i-1]);
            if(atl){rez[i-1]+=1;atl=false;}
        }
        else if(y.length()>=i){
            rez.push_back(y[i-1]);
            if(atl){rez[i-1]+=1;atl=false;}
        }
        else if(atl){rez.push_back('1');atl=false;}
        if(rez[i-1]>57){
            rez[i-1]-=10;
            atl=true;   
        }   
    }
    return rez;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<reverseSum(a,b);
    return 0;
}