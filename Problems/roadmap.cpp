#include<stdio.h>
#include<algorithm>
using namespace std;
struct Interv{
    int S;int B;
};
bool cmpP(Interv &a,Interv &b){//position
    return a.S<b.S;
}
void findGaps(struct Interv I[],int &x){
    sort(I,I+x,cmpP);
    int index=0;
    I[index]=I[0];
    for(int i=1;i<x;i++){
        if(I[i].S<=I[index].B+1){
            I[index].B=max(I[i].B,I[index].B);
        }
        else{
            printf("%d %d\n",I[index].B+1,I[i].S-1);
            I[++index]=I[i];
        }
    }
}
int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    Interv *M=new Interv[x+2];
    M[0].B=-1;M[0].S=-2;//start
    M[x+1].S=y;M[x+1].B=y+1;//limit
    for(int i=1;i<=x;i++){
        scanf("%d%d",&M[i].S,&M[i].B);
        if(M[i].S>M[i].B){swap(M[i].S,M[i].B);}
    }x+=2;//extra space
    findGaps(M,x);
	return 0;
}