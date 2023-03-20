#include<stdio.h>
#include<algorithm>
using namespace std;

struct SP{
unsigned int S;//Sum
unsigned int P;//Position
};
bool cmp(SP &x,SP &y){
    return x.S>y.S;
}
unsigned int maxPassagers(unsigned int loko[],unsigned int &L,unsigned int &MC){
    unsigned int res=0;
    SP CS[L-MC+1];//carriage sum
    CS[0].S=0,CS[0].P=0;
    for(unsigned int i=0;i<MC;i++){
        CS[0].S+=loko[i];
    }//initialize 1.
    for(unsigned int i=1;i<=L-MC;i++){
        CS[i].S=CS[i-1].S-loko[i-1]+loko[i+MC-1];
        CS[i].P=i;
    }//get sums
    sort(CS,CS+L-MC+1,cmp);
    for(unsigned int i=0;i<=MC+1;i++){
        if(CS[i].S*3<=res){break;}
        for(unsigned int j=i+1;j<=MC+i+1;j++){
            if((CS[i].P<CS[j].P+MC)&&(CS[i].P+MC>CS[j].P)){continue;}
            if((CS[j].S*2)+CS[i].S<=res){break;}
            for(unsigned int k=j+1;k<=L;k++){
                if(((CS[i].P<CS[k].P+MC)&&(CS[i].P+MC>CS[k].P))
                ||((CS[j].P<CS[k].P+MC)&&(CS[j].P+MC>CS[k].P))){continue;}
                if(CS[i].S+CS[j].S+CS[k].S<=res){break;}
                if(res<CS[i].S+CS[j].S+CS[k].S){res=CS[i].S+CS[j].S+CS[k].S;break;}
            }
        }
    }
    return res;
} 
int main(){
    unsigned int lokoLen,maxCarriage;
    scanf("%u",&lokoLen);
    unsigned int *loko=new unsigned int[lokoLen];
    for(unsigned int i=0;i<lokoLen;i++){
        scanf("%u",&loko[i]); 
    }
    scanf("%u",&maxCarriage);
    printf("%u",maxPassagers(loko,lokoLen,maxCarriage));
    return 0;
}