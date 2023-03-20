#include<stdio.h>
#define LLI long long int
using namespace std;

int main(){
    LLI discCount, discSize, minDiscCount=1;
    scanf("%lld %lld", &discCount, &discSize);
    for(LLI i = 0, curFreeSpace = discSize; i < discCount; ++i){
        LLI curPartSize, A, B;
        scanf("%lld", &curPartSize);
        if(curPartSize % discSize){
            A = curPartSize / discSize;
            B = curPartSize % discSize;
        }
        else{
            A = (curPartSize / discSize) - 1;
            B = discSize;
        }    
        if(curFreeSpace < B){
            minDiscCount += (A + 1);
            curFreeSpace = discSize - B;
        }
        else{
            minDiscCount += A;
            curFreeSpace -= B;
        }
    }
    printf("%lld", minDiscCount);
    return 0;
}