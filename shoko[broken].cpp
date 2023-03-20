#include<stdio.h>
using namespace std;

int main(){
    unsigned int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if((a*b)==c){printf("0");}
    else if((c%a==0)||(c%b==0)){printf("1");}
    else if((c<a)||(c<b)){printf("2");}
    else if(((c%a)+a)%(b-(c/a))==0){printf("2");}
    else if((a-(c/b))%(c%a)==0){printf("2");} 
    else if(((c%b)+b)%(b-(c/a))==0){printf("2");}
    else if((a-(b/a))%(c%b)==0){printf("2");}
    else{printf("3");}
    return 0;
}