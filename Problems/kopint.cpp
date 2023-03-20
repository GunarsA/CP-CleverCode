#include<stdio.h>
#include<algorithm>
using namespace std;

struct Interv{
  int S;//Sakums
  int B;//Beigas
};
bool cmpInterv(Interv x,Interv y){
	return x.S<y.S;//Salidzina intervalus
}
int binarySearch(Interv x[],int &xLen, Interv y){
    int left=0,right=xLen-1,res;
    while(left<=right){
        res=(right+left)/2;
        if(x[res].B<=y.S){
            left=res+1;
        }
        else if(x[res].S>=y.B){
            right=res-1;
        }
        else{
            while(x[res-1].B>y.S&&x[res-1].S<y.B&&res>0){res--;}//Atrod mazako 
            return res;
        }
    }
    return -1;
}
int KopInt(Interv x[],int &xLen, Interv y){
    int loc=binarySearch(x,xLen,y),res=0;
    if(loc==-1){return res;}
    for(;;loc++){
        int Sakums=max(x[loc].S,y.S);
        int Beigas=min(x[loc].B,y.B);
        if(Beigas-Sakums<0){break;}
        res=max(res,Beigas-Sakums);
    }
    return res;
}
int main(){
  int xC,yC,res=0;//pirmais daudzums, otrais daudzums
  scanf("%d",&xC);
  Interv xInt[xC],y;//pirmie intervali,otrais intervals
  for(int i=0;i<xC;i++){
    scanf("%d%d",&xInt[i].S,&xInt[i].B);
  }
  sort(xInt,xInt+xC,cmpInterv);
  scanf("%d",&yC);
  for(int i=0;i<yC;i++){
    scanf("%d%d",&y.S,&y.B);
    if(y.B-y.S<res){continue;}
    res=max(res,KopInt(xInt,xC,y));
  }
  printf("%d",res);
}
