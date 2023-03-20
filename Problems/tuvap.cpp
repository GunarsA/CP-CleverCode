#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int power(int x,int Pow) { 
    int Res=1; 
    while(Pow>0){ 
        if(Pow&1){
            Res=Res*x; 
        }
        Pow=Pow>>1;
        x=x*x;
    } 
    return Res; 
} 
int sum(int data[],string n,int m,int index){
    if(data[index]>n.length()){
        return -1;
    }
    int sum=0,temp;
    for(int i=1;i<=index;i++){
        temp=0;
        if(n[data[i-1]]=='0'&&data[i]>data[i-1]+1){
            return -1;
        }
        for(int j=data[i-1];j<data[i];j++){
            temp+=(n[j]-'0')*power(10,data[i]-j-1);
        }
        sum+=temp;
    }
    if(sum<=m){
        return sum;
    }
    else{
        return -1;
    }
}
vector<int> res;
void combinations(int data[],int index,string n,int m){
    if(data[index-1]==n.length()){
        if(sum(data,n,m,index-1)!=-1){
            res.push_back(sum(data,n,m,index-1));
        }
        return;
    }
    for(int i=data[index-1]+1;i<=n.length();i++){
        data[index]=i;
        combinations(data,index+1,n,m);
    }
}
int main(){
    int m;
    string n;
    cin>>n>>m;
    int data[n.length()+1];
    data[0]=0;
    combinations(data,1,n,m);
    int biggest=0;
    for(int i=0;i<res.size();i++){
        if(res[i]>biggest){
        biggest=res[i];
        }
    }
    cout<<biggest;
}