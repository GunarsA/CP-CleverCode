#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string sum(string x,string y){
    if(y.length()>x.length()){swap(x,y);}
    string res;
    int lenX=x.length()-1,lenY=y.length()-1;
    bool rem=false;//remainder
    for(int i=0;i<=lenX+1;i++){
        if(lenY>=i){
            res.push_back(y[lenY-i]+x[lenX-i]-'0');
            if(rem){res[i]+=1;rem=false;}
        }
        else if(lenX>=i){
            res.push_back(x[lenX-i]);
            if(rem){res[i]+=1;rem=false;}
        }
        else if(rem){res.push_back('1');rem=false;}
        if(res[i]>57){
            res[i]-=10;
            rem=true;   
        }   
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string x,rez;
    unsigned short int len;
    cin>>x;
    len=(x.length()-1);
    rez=x;
    for(unsigned short int i=0;i<len;i++){
        
        x.erase(0,1);
        rez=sum(rez,x);
    }
    cout<<rez<<endl;
    return 0;
}