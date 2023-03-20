#include<stdio.h>
using namespace std;

int main(){
    unsigned int x,y,resX,resY;
    scanf("%u%u",&x,&y);
    resX=y-1;resY=y;
    for(
    unsigned int i=(resX-1)&(resY-1),j=resX&resY;
    (i>=j)&&(resX>x);
    resX--,resY--,i=(resX-1)&(resY-1)
    ){if(i>j){j=i;}}
    printf("%u %u",resX,resY);
    return 0;
}