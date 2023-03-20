#include<stdio.h> 
#include<stack> 
using namespace std; 

unsigned int findRect(unsigned int graph[],unsigned int &len){ 
    stack<unsigned int> H;//smaller PREVIOUS height location
    unsigned int MaxSize=0,
    tSize,//temperary size
    i=0,//check position
    var;
    while(i<len){ 
        if(H.empty()||graph[H.top()]<=graph[i]){ 
            H.push(i++);//save bigger heights
        }
        else{ 
            var=H.top();
            H.pop();
            tSize=graph[var]*(H.empty()?i:i-H.top()-1); 
            if(tSize>MaxSize){MaxSize=tSize;}
        } 
    } 
    while(!H.empty()){//check smallest sequential heights 
        var=H.top();
        H.pop(); 
        tSize=graph[var]*(H.empty()?i:i-H.top()-1); 
        if(tSize>MaxSize){MaxSize=tSize;}
    } 
    return MaxSize; 
} 
int main() { 
    unsigned int x;
    scanf("%u",&x);
    unsigned int graph[x]; 
    for(unsigned int i=0;i<x;i++){
        scanf("%u",&graph[i]);
    }
    printf("%u",findRect(graph,x));
    return 0; 
}