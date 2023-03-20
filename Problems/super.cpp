#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string multiply(string &x,string &y){
    string res;
    unsigned int xL=x.length(),yL=y.length(),tZ=0;//trailing zeros
    res.resize(xL+yL,'0');
    for(unsigned int i=0;i<x.length();i++){
        for(unsigned int j=0;j<y.length();j++){
            res[i+j]+=((x[xL-i-1]-48)*(y[yL-j-1]-48))%10;//multiply
            res[i+j+1]+=(x[xL-i-1]-48)*(y[yL-j-1]-48)/10;//add multiplication remainder
            res[i+j+1]+=(res[i+j]-48)/10;//add sum remainder
            res[i+j]=((res[i+j]-48)%10)+48;//remove remainder
        }
    }
    reverse(res.begin(),res.end());
    while(res[tZ]=='0'){tZ++;}//count trailing zeros
    res.erase(0,tZ);
    return res;
}
unsigned int strNumSum(string &x){
    unsigned int res=0;
    for(unsigned int i=0;i<x.length();i++){
        res+=x[i]-48;
    }
    return res;
}
unsigned int intNumSum(unsigned int &x){
    unsigned int res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    string x,y;
    cin>>x>>y;
    x=multiply(x,y);
    unsigned int res=strNumSum(x);
    while(res>9){
        res=intNumSum(res);
    }
    cout<<res<<endl;
    return 0;
}