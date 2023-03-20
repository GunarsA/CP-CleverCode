#include<stdio.h>
using namespace std;

unsigned int devider(unsigned int &x){
    for(unsigned int i=2;i<=1000;i++){
        if(x%i==0){return i;}
    }
    return 1000;
}
int main(){
    unsigned int N,counter=0,i;
    scanf("%u",&N);
    i=(N/devider(N));
    counter=(N-i)-1;
    while(i>0){
        counter++;
        if(N%i==0){break;}
        i--;
    }
    printf("%u",counter);
    return 0;
}
