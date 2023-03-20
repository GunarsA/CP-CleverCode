#include<stdio.h>
using namespace std;

void getSum(int x[],int &y){
    for(int i=1;i<=y;i++){
        x[i]+=x[i-1];
    }
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    int C[N+1];
    C[0]=0;//start
    int Q[M][2];
    for(int i=1;i<=N;i++){
        scanf("%d",&C[i]);
    }
    for(int i=0;i<M;i++){
        scanf("%d%d",&Q[i][0],&Q[i][1]);
    }
    getSum(C,N);
    for(int i=0;i<M;i++){
        printf("%d\n",C[Q[i][1]]-C[Q[i][0]-1]);
    }
    return 0;
}