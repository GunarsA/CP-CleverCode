#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(int &a,int &b){
    return a>b;
}
int gcd(int a,int b){ 
    if(b==0){return a;} 
    return gcd(b,a%b);     
}
int mazDal(int var[32]){
    int letterCount=0,res;
        for(int i=0;i<32;i++){
            if(var[i]!=0){letterCount++;}
        }
        sort(var,var+31,cmp);
        res=var[0];
        for(int i=1;i<=letterCount;i++){
            res=gcd(res,var[i]);
        }
    return res;
}
bool same(char **dobe,int &y,int &x,int &a,int &b){
    for(int kY=0;kY<y;kY++){
        for(int kX=0;kX<x;kX++){
            for(int kfY=0;kfY<a/y;kfY++){
                for(int kfX=0;kfX<b/x;kfX++){         
                    if(dobe[kY][kX]!=dobe[kY+(y*kfY)][kX+(x*kfX)]){
                        return false;
                    }
                }
            }
        }
    } 
    return true;
}
int waysToDivide(int a,int b){
    int x=0,y=0;
    for(int i=1;i<=a;i++){
        if(a%i==0){x++;}
    }
    for(int i=1;i<=b;i++){
        if(b%i==0){y++;}
    }
    return x*y;
}
int main(){
    int a,b,var[32]={};
    scanf("%d%d",&a,&b);
    int rezX=b,rezY=a;
    char** dobe = new char*[a];
    for(int i=0;i<a;i++){
        dobe[i]=new char[b];
    }
    for(int i=0;i<a;i++){
        scanf(" %s",dobe[i]);
        for(int j=0;j<b;j++){
            var[dobe[i][j]-97]++;
        }
    }
    int D=mazDal(var);
    if(D==1){
        printf("1");
    }
    else{
        for(int garY=1,garX=1;garY<=a;garY++){
            if(a%garY!=0){continue;}
            for(garX=1;garX<=b;garX++){ 
                if(b%garX!=0){continue;}
                if((a*b)/(garY*garX)>D){continue;}
                if((garY*garX)>(rezY*rezX)){continue;}
                if(same(dobe,garY,garX,a,b)){rezY=garY;rezX=garX;break;} 
            }
        }
        printf("%d",waysToDivide(a/rezY,b/rezX));
    }
    return 0;
}