#include<stdio.h>
#include<vector>
using namespace std;

struct Solution{
    unsigned long long int s;//small
    unsigned long long int m;//medium
    unsigned long long int l;//large
};
unsigned long long int sum(Solution x){
    return x.s+x.m+x.l;
}
void Insert(vector<Solution> &x,Solution y){
    for(unsigned int i=0;i<x.size();i++){
        if(sum(x[i])>sum(y)){x.insert(x.begin()+i,y);break;}
        if(i==x.size()-1){x.push_back(y);break;}
    }
}
//nextMarkovNumber
Solution NMN(Solution &x,bool biggest=true){
    Solution res;
    if(biggest){
        res.l=(x.m*x.l*3)-x.s;
        res.m=x.l;
        res.s=x.m;
    }
    else{
        res.l=(x.s*x.l*3)-x.m;
        res.m=x.l;
        res.s=x.s;
    }
    return res;
} 
int main(){
    unsigned int x;
    vector<Solution> oList;//orderes list
    Solution Rnd={1,1,1};
    oList.push_back(Rnd);  
    vector<Solution> uList;//unordered list
    
    scanf("%u",&x);
    for(unsigned int i=1;i<x;i++){
        bool S=false;
        Rnd=NMN(oList[i-1],S);
        if(uList.empty()){
            oList.push_back(Rnd);
            if(i>2){uList.push_back(NMN(oList[i-1]));}
            continue;
        }
        if(sum(Rnd)<sum(uList[0])){
            oList.push_back(Rnd);
        }
        else{
            oList.push_back(uList[0]);
            Insert(uList,Rnd);
            uList.erase(uList.begin());
        }
        Insert(uList,NMN(oList[i-1]));
    }
    printf("%llu",sum(oList[x-1])); 
    return 0;
}