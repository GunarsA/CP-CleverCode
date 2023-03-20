#include<stdio.h>
using namespace std;

bool isPrime(short int &x){
    for(short int y=2;y*y<=x;y++){
        if(x%y==0){return false;}
    }
    return true;
}
int main(){
    int C;
    scanf("%d",&C);
    short int x[C];
    for(int i=0;i<C;i++){
        scanf("%hu",&x[i]);
    }
    for(int i=0;i<C;i++){
        if(isPrime(x[i])){printf("%c",x[i]);}
    }
    return 0;
}