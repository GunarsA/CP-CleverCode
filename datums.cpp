#include<stdio.h>
using namespace std;

int main(){
    int date,res;
    scanf("%d",&date);
    date%100>16?res=1900:res=2000;
    res+=date%100;//year
    date/=100;
    res-=date%100;//month
    date/=100;
    res-=date%100;//day
    printf("%d",res);
    return 0;
}