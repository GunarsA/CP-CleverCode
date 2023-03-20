#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

struct loc{
    int X;
    int Y;
};
loc F(int y,int x){
    loc res={x,y};
    return res;
}
int mazeExitDistance(string C[],int &lenY,int &lenX){
    int res=-1,MC[lenY][lenX]={};//move count
    vector<loc> end(1);
    for(int i=0;i<lenY;i++){
        for(int j=0;j<lenX;j++){
            if(C[i][j]=='@'){if((i==0)||(j==0)||(i==lenY-1)||(j==lenX-1)){return 0;}end[0].Y=i;end[0].X=j;break;}
        }
    }
    loc E={0,0};//exit
    int EC=1;//end count
    for(;;){
        bool A=false;//answer
        int T=EC;
        EC=0;
        for(int i=0;i<T;i++){
                for(int j=0;j<T;j++){
                    int cY=end[j].Y,cX=end[j].X;
                    if((cY==0)||(cX==0)||(cY==lenY-1)||(cX==lenX-1)){
                        res=MC[cY][cX];
                        EC++;
                        C[cY][cX]='*';
                        if(cY==0){E.X=cX;E.Y=cY+1;}
                        else if(cX==0){E.X=cX+1;E.Y=cY;}
                        else if(cY==lenY-1){E.X=cX;E.Y=cY-1;}
                        else if(cX==lenX-1){E.X=cX-1;E.Y=cY;}
                        if(C[E.Y][E.X]!='@'){C[E.Y][E.X]='*';}
                        end.push_back(E);
                        A=true; 
                    }
            }
            int cY=end[i].Y,cX=end[i].X,cM=MC[cY][cX];
            if(A){end.erase(end.begin(),end.begin()+T);break;}
            if((C[cY+1][cX]!='#')&&(C[cY+1][cX]!='@')){
                if(MC[cY+1][cX]==0){
                    MC[cY+1][cX]=cM+1;
                    end.push_back(F(cY+1,cX));
                    EC++;
                }
            }
            if((C[cY-1][cX]!='#')&&(C[cY-1][cX]!='@')){         
                if(MC[cY-1][cX]==0){
                    MC[cY-1][cX]=cM+1;
                    end.push_back(F(cY-1,cX));
                    EC++;
                }
            }
            if((C[cY][cX+1]!='#')&&(C[cY][cX+1]!='@')){
                if(MC[cY][cX+1]==0){
                    MC[cY][cX+1]=cM+1;
                    end.push_back(F(cY,cX+1));
                    EC++;
                }
            }
            if((C[cY][cX-1]!='#')&&(C[cY][cX-1]!='@')){
                if(MC[cY][cX-1]==0){
                    MC[cY][cX-1]=cM+1;
                    end.push_back(F(cY,cX-1));
                    EC++;
                }
            }
        }
        if(A){break;}
        if(EC==0){return res;}
        end.erase(end.begin(),end.begin()+T);
    }
    for(;;){//end count
        bool A=false;//answer
        int T=EC;
        EC=0;
        for(int i=0;i<T;i++){
            int cY=end[i].Y,cX=end[i].X;
            if(C[cY][cX]=='@'){A=true;break;}
            else{C[cY][cX]='*';}

            if((C[cY+1][cX]!='#')&&(C[cY+1][cX]!='@')){
                if(MC[cY+1][cX]<MC[cY][cX]){
                    //C[cY+1][cX]='*';
                    end.push_back(F(cY+1,cX));
                    EC++;
                }
            }
            if((C[cY-1][cX]!='#')&&(C[cY-1][cX]!='@')){
                 if(MC[cY-1][cX]<MC[cY][cX]){
                    //C[cY-1][cX]='*';
                    end.push_back(F(cY-1,cX));
                    EC++;
                }
            }
            if((C[cY][cX+1]!='#')&&(C[cY][cX+1]!='@')){
                 if(MC[cY][cX+1]<MC[cY][cX]){
                    //C[cY][cX+1]='*';
                    end.push_back(F(cY,cX+1));
                    EC++;
                }
            }
            if((C[cY][cX-1]!='#')&&(C[cY][cX-1]!='@')){
                 if(MC[cY][cX-1]<MC[cY][cX]){
                    //C[cY][cX-1]='*';
                    end.push_back(F(cY,cX-1));
                    EC++;
                }
            }
        }
        if(A){break;}
        if(EC==0){return res;}
        end.erase(end.begin(),end.begin()+T);
    }
    return res;
}
int main(){
    int lenY,lenX;
    scanf("%d%d ",&lenY,&lenX);
    char cave[lenY][lenX];
    for(int i=0;i<lenY;i++){
        for(int j=0;j<lenX;j++){
            scanf("%c",&cave[i][j]);
        }
        //scanf("%c ",&cave[i][lenX-1]);
    }
    //printf("%d\n",mazeExitDistance(cave,lenY,lenX));
    for(int i=0;i<lenY;i++){
        for(int j=0;j<lenX;j++){
            printf("%c",cave[i][j]);
        }
        printf("\n");
    }
    return 0;
}


