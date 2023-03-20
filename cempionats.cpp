#include<stdio.h>
#include<algorithm>
using namespace std;

struct card{
    int V;//Value
    char M;//Mast
};
bool cmp(card &a,card &b){
    return a.V<b.V;
}
int combinationPower(card H[]){
    sort(H,H+5,cmp);
    bool Straight=false;
    for(int i=0;i<5;i++){
        if(i==4){
            Straight=true;
            break;
        }
        if(H[i].V!=H[i+1].V-1){
            if(i!=3||H[4].V!=14||H[0].V!=2){
                break;
            }
        }
    }
    bool Flush=false;
    for(int i=1;i<=5;i++){
        if(i==5){
            Flush=true;
            break;
        }
        if(H[0].M!=H[i].M){
            break;
        }
    }
    bool Pairs[4]={};
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(H[i].V!=H[j].V){i=j-1;break;}
            if(Pairs[j-i]){
                Pairs[0]=true;
            }
            else{
                Pairs[j-i]=true;
            }
            if(j==4){i=4;}
        } 
    }
    if(Straight&&Flush){return 9;}
    if(Pairs[3]){return 8;}
    if(Pairs[0]&&Pairs[2]){return 7;}
    if(Flush){return 6;}
    if(Straight){return 5;}
    if(Pairs[2]){return 4;}
    if(Pairs[0]&&Pairs[1]){return 3;}
    if(Pairs[1]){return 2;}
    return 1;
}
int main(){
    int amount;
    scanf("%d",&amount);
    for(int i=0;i<amount;i++){
        card hand[5];
        scanf("%d %c%d %c%d %c%d %c%d %c",  
            &hand[0].V,&hand[0].M,
            &hand[1].V,&hand[1].M,
            &hand[2].V,&hand[2].M,
            &hand[3].V,&hand[3].M,
            &hand[4].V,&hand[4].M
        );
        int P=combinationPower(hand);
        if(P==1){printf("High card\n");continue;}
        if(P==2){printf("Pair\n");continue;}
        if(P==3){printf("Two pairs\n");continue;}
        if(P==4){printf("Three of a kind\n");continue;}
        if(P==5){printf("Straight\n");continue;}
        if(P==6){printf("Flush\n");continue;}
        if(P==7){printf("Full House\n");continue;}
        if(P==8){printf("Four of a kind\n");continue;}
        if(P==9){printf("Straight flush\n");continue;}
    }
    return 0;
}