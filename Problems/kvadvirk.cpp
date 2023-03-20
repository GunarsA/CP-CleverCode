#include<stdio.h>
#include<cmath>
using namespace std;

int elementAtPosition(int &x){
    for(long long int pos=0,lenP=10,digitC=1,pRoute=0;;digitC++,lenP*=10){
        long long int route,cPos;
        route=floor(sqrt(lenP)-1e-3);//curent interval last element
        cPos=(route-pRoute)*digitC;//current interval of positions
        if(pos+cPos>=x){
            int res,
            xLoc=x-pos,//x location
            xMod=digitC-((xLoc-1)%digitC);// reverse modul of x's number
            long long int xRoute=pRoute+((xLoc-1)/digitC)+1;//x route
            xRoute*=xRoute;//x square
            while(xMod>0){//find right digit
                res=xRoute%10;
                xRoute/=10;
                xMod--;
            }
            return res;
        }
        pRoute=route;//previous route
        pos+=cPos; 
    }
}
int main(){
    int x;
    scanf("%d",&x);
    printf("%d",elementAtPosition(x));
    return 0;
}