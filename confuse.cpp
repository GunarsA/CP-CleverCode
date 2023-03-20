#include<stdio.h>
#include<climits>
using namespace std;

int main(){
    int len,confuse;
    long long int min=INT_MAX,max=INT_MIN;
    scanf("%d%d",&len,&confuse);
    for(int i=0,element;i<len;i++){
        scanf("%d",&element);
        if(element<=min){min=element;}
        if(element>=max){max=element;}
    }
    printf("%lld",max-min);
    return 0;
}