#include<stdio.h>
#include<algorithm>
using namespace std;

struct area{
    int x;
    int y;
};
bool compare(area &a, area &b){
    if(a.x!=b.x){return a.x<b.x;}
    else{return a.y<b.y;}
}
bool canFit(area Size[3]){
    if(Size[0].x<=Size[1].x&&Size[0].y<=Size[1].y
    &&Size[1].x<=Size[2].x&&Size[1].y<=Size[2].y){
        return true;
    }
    return false;
}
int  main(){
    int taskC;
    scanf("%d",&taskC);
    for(int i=0;i<taskC;i++){
        area Boxes[3];
        scanf("%d%d%d%d%d%d",&Boxes[0].x,&Boxes[0].y,&Boxes[1].x,&Boxes[1].y,&Boxes[2].x,&Boxes[2].y);
        sort(Boxes,Boxes+3,compare);
        canFit(Boxes)?
        printf("YES\n"):
        printf("NO\n");
    }
    return 0;
}