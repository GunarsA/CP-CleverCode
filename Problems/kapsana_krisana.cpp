#include<stdio.h>
using namespace std;

int main(){
    int PQ,//People Quantity
    RC,//Rating Change
    QC;//Question Count
    scanf("%d%d",&PQ,&RC);
    int *P=new int[PQ]; 
    for(int i=0;i<PQ;i++){
        scanf("%d",&P[i]);
    }
    scanf("%d",&QC);
    //Start, End, Distance, Answer
    for(int i=0,S,E,D,A;i<QC;i++){
        scanf("%d%d",&S,&E);
        S<E?
        D=(P[S-1]-P[E-1]):  
        D=(P[E-1]-P[S-1]);
        A=(D/(RC*2))+1;
        printf("%d ",A);
    }
    return 0;
}