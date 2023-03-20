#include<stdio.h>
using namespace std;

unsigned int number(bool dip[5][3]){
    if(dip[0][1]==true){
        if(dip[0][2]==true){
            if(dip[1][0]==true){
                if(dip[1][2]==true){
                    if(dip[3][0]==true){
                        if(dip[2][1]==true){
                            return 8; 
                        }
                        else{
                            return 0;
                        }
                         
                    }
                    else{
                        return 9;
                    }
                }
                else{
                    if(dip[3][0]==true){
                        return 6;
                    }
                    else{
                        return 5;
                    }
                }
            }
            else{
               if(dip[2][0]==true){
                   if(dip[3][0]==true){
                       return 2;
                   }
                   else{
                       return 3;
                   }
               }
               else{
                   return 7;
               }
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 4;
    }
}
int main(){
    unsigned int N,M,res,loc[1][2];
    scanf("%u%u",&N,&M);
    bool display[5][3],find=false;
    char q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf(" %c",&q);
            if((q=='#')&&(find==false)){display[0][0]=true;loc[0][0]=i;loc[0][1]=j;find=true;continue;}
            if((j<(loc[0][1]+3)&&(j>=loc[0][1]))&&i<(loc[0][0]+5)&&(i>=loc[0][0])){
                if(q=='#'){display[i-loc[0][0]][j-loc[0][1]]=true;}
                else{display[i-loc[0][0]][j-loc[0][1]]=false;}
            }
        }
    }
    printf("%u",number(display));
    return 0;
}