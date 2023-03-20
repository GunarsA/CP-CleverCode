#include<stdio.h>
using namespace std;

int main(){
    long long int SIZE,Odd=0,Both;
    scanf("%lld",&SIZE);
    Both=SIZE*(SIZE+1)/2;
    int LL[SIZE];//LowestLevel
    for(int i=0;i<SIZE;i++){
        scanf("%d",&LL[i]);
    }
    for(int i=0;i<SIZE;){
        if(LL[i++]%2){
            long long Area=1;
            while(LL[i]%2&&i<SIZE){
                i++,Area++;
            }
            Odd+=((Area*(Area-1))/2)+Area;
        }
    }
    printf("%lld %lld",Odd,Both-Odd);
    return 0;
}