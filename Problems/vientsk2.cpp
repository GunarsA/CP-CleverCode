#include<stdio.h>
#include<vector>
#include<unordered_map>
#define GC getchar
#define PC putchar
using namespace std; 
  
void scanInt(int &x){
    register int c=GC();
    bool negatve=0;
    x=0;
    for(;(c<48||c>57);c=GC());
    if(c=='-'){
        negatve=1;
        c=GC();
    }
    for(;c>47&&c<58;c=GC()){
        x=(x<<1)+(x<<3)+c-48;
    }
    if(negatve){
        x=-x;
    }
}
inline void writeInt(int x){
    string xS=to_string(x);
    for(auto i:xS){
        PC(i);
    }
}
int nonRepeating(vector<int> &arr,int &len){ 
    unordered_map<int,int> Occurences; 
    for(int i=0;i<len;i++){
        Occurences[arr[i]]++;
    }
    for(auto x:Occurences){
        if(x.second==1){
            return x.first;
        }
    }
    return -1;
}
int main() { 
    int Quantity;
    scanInt(Quantity);
    vector<int> Numbers(Quantity);
    for(int i=0;i<Quantity;i++){
        scanInt(Numbers[i]);
    }
    writeInt(nonRepeating(Numbers,Quantity)); 
    return 0; 
}