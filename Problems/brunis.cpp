#include<stdio.h>
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
int main(){
    unsigned int x,y,x2,y2;
    string size,res="1";
    cin>>size;
    scanf("%u%u",&y,&x);
    scanf("%u%u",&y2,&x2);
    for(unsigned int i=y;i<y2;i++){
        res=multiply(res,size);
    }
    if(y>y2){res="0";}
    cout<<res<<endl;
    return 0;
}