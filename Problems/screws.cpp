#include<stdio.h>
#include<algorithm>
using namespace std;

int binarySearch(int arr[],int len,int x){
    int left=0,right=len+1,mid=(left+right)/2;
    if(x>arr[len]){return len;}
    else if(x<arr[1]){return 0;}
    while((arr[mid]>=x)||(arr[mid+1]<x)){
        if(arr[mid]>=x){right=mid;}
        else if(arr[mid+1]<x){left=mid;}
        mid=(left+right)/2;
    }
    return mid;
}
int main(){
    int Jc,Sc;//job count, screw count
    scanf("%d",&Jc);
    int J[Jc][2];
    for(int i=0;i<Jc;i++){
        scanf(" %d%d",&J[i][0],&J[i][1]);
    }
    scanf("%d",&Sc);
    int S[Sc+2];
    S[0]=0;S[Sc+1]=2147483647;
    for(int i=1;i<=Sc;i++){
        scanf("%d",&S[i]);
    }
    sort((S+1),(S+1)+Sc);
    for(int i=0;i<Jc;i++){
        if(J[i][0]==J[i][1]){printf("0\n");}
        else{printf("%d\n",binarySearch(S,Sc,J[i][1])-binarySearch(S,Sc,J[i][0]));}
    }
    return 0;
}