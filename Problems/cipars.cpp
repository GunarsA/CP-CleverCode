#include<stdio.h>
using namespace std;

int elementAtPosition(int &x){
    int res=-1;
    for(long long int pos=0,digitC=1,pLimit=0,limit=9;;digitC++){
        long long int cPos=(limit-pLimit)*digitC;//current interval of positions
        if(pos+cPos>=x){
            int xLoc=x-pos;//x location
            int xMod=digitC-((xLoc-1)%digitC);// reverse modul of x's number
            long long int xPos=pLimit+((xLoc-1)/digitC)+1;//x limit
            while(xMod>0){//find right digit
                res=xPos%10;
                xPos/=10;
                xMod--;
            }
            return res;
        }
        pLimit=limit;//previous limit
        limit=((limit+1)*10)-1;//next limit
        pos+=cPos;//checked positions
    }
}
int main(){
    int x;
    scanf("%d",&x);
    printf("%d",elementAtPosition(x));
    return 0;
}