#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

string intToString(int x){
    string res="";
    while(x>0){
        string Insert=" ";
        Insert[0]=(x%10)+48;
        res.insert(0,Insert);
        x/=10;
    }
    return res;
}
string multiply(string x,string y){
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
    int F;
    string Factorial="1";
    int Zeros=0;
    scanf("%d",&F);
    for(int i=2;i<=F;i++){
        Factorial=multiply(Factorial,intToString(i));
    }
    for(int i=0;i<Factorial.length();i++){
        if(Factorial[i]=='0'){Zeros++;}
    }
    printf("%d",Zeros);
    return 0;
}