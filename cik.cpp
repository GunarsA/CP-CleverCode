#include<stdio.h>
using namespace std;
unsigned int x,y,z[100]={},rez,pR=10,len;
int main(){
    scanf("%d%d",&x,&y);
    for(unsigned short int i=0;x>0; i++){
        z[i]=x%10;
        x/=10;
        len=i;
    }
    if(z[0]<y){rez=(y-z[0]);}
    else if(z[0]>=y){rez=((y+10)-z[0]);}
    for(unsigned short int i=0;i<=len;i++){
        if((z[i]==9)&&(i<2)){
            while(z[i]==9){i++;}
            if((z[i]+1)==y){pR=10-z[0];}
            i++;
        }
        if((z[i]==y)&&(i>0)){pR=1;}
        if(((z[i+1]+1)==y)&&(i<1)){pR=10-y;}
        if(pR<rez){rez=pR;}
    }
    printf("%d",rez);
    return 0;
}