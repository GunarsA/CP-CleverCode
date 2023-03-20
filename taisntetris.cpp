#include<stdio.h>
using namespace std;

int main(){
    int xLen,yLen,B=0,res=0;
    scanf("%d%d",&yLen,&xLen);
    int H[xLen]={};//height
    bool Rnd[xLen]={};
    for(int i=0;i<yLen;i++){
        char level[xLen];
        scanf(" %s",&level[0]);
        for(int j=0;j<xLen;j++){
            if(level[j]=='#'){
                if(!B){B=yLen-i;}
                H[j]++;
            }
        }
    }
    for(int i=0;i<xLen;i++){
        if((H[i]<B)&&(Rnd[i]==false)){res++;}
        while(H[i]>=H[i+1]){
            if(H[i]==H[i+1]){i++;}
            else{
               for(int j=i+1;j<xLen;j++){
                    if(H[j]>=H[i]){
                        if(H[j]==H[i]){Rnd[j]=true;}
                        break;
                    }
               }
               break;
            }
            
        }
    }
    printf("%d",res);
    return 0;
}
