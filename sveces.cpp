#include<stdio.h>
#include<deque> 
using namespace std; 
  
//Biggest Sliding Window Maximum
unsigned int BSWM(unsigned int T[],unsigned int &L,unsigned int &W){
    unsigned int res;
    deque<unsigned int> UE(W);//Useful Elements
    for(unsigned int i=0;i<W;i++){ 
        while((!UE.empty())&&T[i]>=T[UE.back()]){
            UE.pop_back();
        }
        UE.push_back(i); 
        res=T[UE.front()];
    } 
    for(unsigned int i=W;i<L;i++) { 
        while((!UE.empty())&&UE.front()<=i-W){
            UE.pop_front();
        }
        while((!UE.empty())&&T[i]>=T[UE.back()]){
            UE.pop_back(); 
        }
        UE.push_back(i); 
        if(res>T[UE.front()]){res=T[UE.front()];}
    }
    return res;
} 
int main(){ 
    unsigned int CC,Window;//Candle Count
    scanf("%u%u",&CC,&Window);
    unsigned int BurnTime[CC];
    for(unsigned int i=0;i<CC;i++){
        scanf("%u",&BurnTime[i]);
    }
    printf("%u",BSWM(BurnTime,CC,Window)); 
    return 0; 
} 