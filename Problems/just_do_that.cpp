#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
//-------------------------------------------------------------------------------
string IntToStr(int x){
    string res;
    while(x>0){
        char Digit=(x%10)+48;
        x/=10;
        res.insert(0,1,Digit);
    }
    return res;
}
//-------------------------------------------------------------------------------
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
//-------------------------------------------------------------------------------
string longDivision(string number, int divisor) 
{ 
    // As result can be very large store it in string 
    string ans; 
    
    // Find prefix of number that is larger 
    // than divisor. 
    int idx = 0; 
    int temp = number[idx] - '0'; 
    while (temp < divisor) 
       temp = temp * 10 + (number[++idx] - '0'); 
      
    // Repeatedly divide divisor with temp. After  
    // every division, update temp to include one  
    // more digit. 
    while (number.size() > idx) 
    { 
        // Store result in answer i.e. temp / divisor 
        ans += (temp / divisor) + '0'; 
          
        // Take next digit of number 
        temp = (temp % divisor) * 10 + number[++idx] - '0'; 
    } 
      
    // If divisor is greater than number 
    if (ans.length() == 0) 
        return "0"; 
      
    // else return ans 
    return ans; 
} 
//-------------------------------------------------------------------------------
string NIPT(int row,int column){//Number In Pascal's Triangle
    string res="1"; 
    for(int i=1;i<=column;i++){
        if(i==column){return res;}
        if(row-(i-1)==column){return res;}
        int T=(row-i);
        string temp=IntToStr(T);
        //cout<<res<<"|"<<T<<"|"<<temp<<"|"<<endl;
        res=multiply(res,temp);
        res=longDivision(res,i);
    }
}
//-------------------------------------------------------------------------------
int main(){
    int x,y;
    cin>>x>>y;
    cout<<NIPT(x+1,y+1);
    return 0;
}