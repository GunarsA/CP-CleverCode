#include<stdio.h>
#include<algorithm>
using namespace std;

bool binarySearch(int list[],int listLen,int x){
    int left=0,right=listLen-1,mid=(left+right)/2;
    if(x<list[0]||x>list[listLen-1]){return false;}
    while(left<=right){
        if(list[mid]==x){return true;}
        else if(list[mid]>x){right=mid-1;}
        else if(list[mid]<x){left=mid+1;}
        mid=(left+right)/2;
    }
    return false;
}
int main(){
    int ilze,sumI=0,karlis,sumK=0,res=0;
    scanf("%d",&ilze);
    int candiesI[ilze];
    for(int i=0;i<ilze;i++){
        scanf("%d",&candiesI[i]);
        sumI+=candiesI[i];
    }
    sort(candiesI,candiesI+ilze);
    scanf("%d",&karlis);
    int candiesK[karlis];
    for(int i=0;i<karlis;i++){
        scanf("%d",&candiesK[i]);
        sumK+=candiesK[i];
    }
    sort(candiesK,candiesK+karlis);
    for(int i=0,dif=sumK-sumI;i<ilze;i++){
        if(dif%2){break;}
        int element=candiesI[i]+(dif/2);
        if(binarySearch(candiesK,karlis,element)){
            res++;
        }
    }
    printf("%d",res);
    return 0;
}