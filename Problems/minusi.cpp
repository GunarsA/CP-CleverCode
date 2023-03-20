#include<stdio.h>
using namespace std;

int main(){
    int x;
    scanf("%d",&x);
    for(int i=1,sum=1;;sum+=++i){
        if(sum>=x){
            if((sum-x)%2==0){
                printf("%d",i);
            }
            else if((sum+i+1-x)%2==0){
                printf("%d",i+1);
            }
            else{
                printf("%d",i+2);
            }
            break;
        }
    }
    return 0;
}