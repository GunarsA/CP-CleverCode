#include<stdio.h>
#include<algorithm>
using namespace std;

struct day{
    int D;//day
    bool S;//stay
};
bool cmp(day &X,day &Y){
    if(X.D!=Y.D){return X.D<Y.D;}
    if(X.S){return true;}else{return false;}
}
int main(){
    int C,res=0;
    scanf("%d",&C);
    day visas[C*2];
    for(int i=0;i<C*2;i++){
        char date[11];
        scanf("%s",&date[0]);
        visas[i].D=(date[0]-48)*1e8;
        visas[i].D+=(date[1]-48)*1e7;
        visas[i].D+=(date[2]-48)*1e6;
        visas[i].D+=(date[3]-48)*1e5;
        visas[i].D+=(date[5]-48)*1e4;
        visas[i].D+=(date[6]-48)*1e3;
        visas[i].D+=(date[8]-48)*1e2;
        visas[i].D+=(date[9]-48);
        i%2==0?visas[i].S=true:visas[i].S=false;
    }
    sort(visas,visas+(C*2),cmp);
    for(int i=0,j=0;i<C*2;i++){
        if(visas[i].S){j++;}
        else{j--;}
        if(res<j){res=j;}
    } 
    printf("%d",res);
    return 0;
}