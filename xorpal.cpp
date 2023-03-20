#include<stdio.h>
using namespace std;

int main(){
    int strL,mid;
    bool F=false;
    scanf("%u",&strL);
    char str[strL];
    mid=((strL+1)/2)-1;
    scanf("%s",&str[0]);
    for(int i=0,j=(strL+1)%2;i<=mid;i++){
        if(str[mid-i]==str[mid+i+j]){
            if((str[mid-i]=='1')&&(F||i==mid)){printf("0");}
            else if(F||i==mid){printf("0");}
        }
        else{
            if(str[mid+i+j]=='1'){printf("1");F=true;}
            else{printf("1");F=true;}
        }
    }
    return 0;
}