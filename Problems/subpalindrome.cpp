#include<stdio.h>
#include<algorithm>
using namespace std;

int countSubPalindromes(char S[],int &L){
    int P[L+1],res=0;//palidrome count
    for(int i=0;i<=1;i++){
        P[0]=0;
        for(int j=1,R=0,k;j<L;j+=k,res+=R,R=max(R-k,0)){
            while((S[j-R-1]==S[j+i+R])&&(j>R)){R++;}
            P[j-1]=R;
            for(k=1;(P[j-k-1]!=R-k)&&(k<R);res+=P[j+k-1],k++){
                P[j+k-1]=min(P[j-k-1],R-k);
                printf("test\n");
            }
            printf("%u\n",res);
        }
    }
    return res+L;
}
int main(){
    int strL;
    scanf("%d",&strL);
    char str[strL+1];
    scanf("%d",&str[0]);
    str[strL]='#';
    printf("%d",countSubPalindromes(str,strL));
    return 0;
} 