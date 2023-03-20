#include<stdio.h>
#include<limits.h>
using namespace std;

int main(){
    int Len,res=0;
    scanf("%d",&Len);
    int Cart[Len];
    for(int i=0;i<Len;){
        scanf("%d",&Cart[i++]);
    }
    for(int i=Len,Big=INT_MAX;i>0;){
        if(Cart[--i]<Big){
            res++;
            Big=Cart[i];
        }
    }
    printf("%d",res);
    return 0;
}