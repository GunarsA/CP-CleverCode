#include<iostream> 
#include<algorithm>
using namespace std; 

string sum(string Long,string Short){
    string res;
    int lenL=Long.length()-1,lenS=Short.length()-1;
    bool rem=false,Swap=false;
    //---- "Long" has to be longer than "Short" ----
    if(Short.length()>Long.length()){
        swap(Long,Short);
        lenL=Long.length()-1;
        lenS=Short.length()-1;
        Swap=true;
    }
    for(int i=0;i<=lenL+1;i++){
        if(lenS>=i){//Add both
            res.push_back(Short[lenS-i]+Long[lenL-i]-'0');
            if(rem){res[i]++;rem=false;}
        }
        else if(lenL>=i){//Add longest
            res.push_back(Long[lenL-i]);
            if(rem){res[i]++;rem=false;}
        }
        else if(rem){//Add remainder
            res.push_back('1');
            rem=false;
        }
        if(res[i]>57){//Remove overflow
            res[i]-=10;
            rem=true;   
        }   
    }
    //-- Swap variables back if needed --
    if(Swap){
        swap(Long,Short);
    }
    reverse(res.begin(),res.end());
    return res;
}
//--------------------------------------------------------
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
//--------------------------------------------------------
string getCatalanNumber(int x){ 
    string catalanNumber[x+1]; 
    catalanNumber[0]=catalanNumber[1]="1"; 
    for(int i=2;i<=x;i++) { 
        catalanNumber[i]="0"; 
        for(int j=0;j<i;j++){
            catalanNumber[i]=
            sum(
                catalanNumber[i],
                multiply(
                    catalanNumber[j],
                    catalanNumber[i-j-1]
                )
            ); 
        }
    } 
    return catalanNumber[x]; 
} 
//--------------------------------------------------------
int main(){ 
    int x;
    cin>>x;
    x%2?
    cout<<"0":
    cout<<getCatalanNumber(x/2);
    return 0; 
} 