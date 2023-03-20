#include<stdio.h>
#include<queue>
using namespace std;

struct Loc{
    int Y;//X Axis
    int X;//Y Axis
};
struct Key{
    Loc Pos;//Location
    int Lvl;//Level
    int Len;//Length
};
//Make Key
Key MK(Loc &a,int b,int c){
    Key res={a,b,c};
    return res;
}
//Get Distance
int GD(Loc &a,Loc &b){
    int res=0;
    a.Y>b.Y?
    res+=a.Y-b.Y:
    res+=b.Y-a.Y;
    a.X>b.X?
    res+=a.X-b.X:
    res+=b.X-a.X;
    return res;
}
//Get Smallest Distance
int GSD(int &TL,int TX[],Loc &L,Loc &R,Loc KL[]){
    queue <Key> Path;
    //-------- Iterate First Elements ---------
    Path.push(MK(L,1,GD(R,KL[TX[0]])));
    Path.push(MK(R,1,GD(L,KL[TX[0]])));
    //-------- Find Best Paths -----------
    for(int CurLvl=1,T;CurLvl<TL;CurLvl++){
        //------- Make First Overlaping Element ------------
        Key OverLap=
        MK(
            KL[TX[CurLvl-1]],
            CurLvl+1,
            Path.front().Len+
            GD(
                Path.front().Pos,
                KL[TX[CurLvl]]
            )
        );
        //----- Go Trough All Elements In Current Level ----
        for(;Path.front().Lvl==CurLvl;Path.pop()){
            //-------- Push New Unique Element --------
            if(Path.front().Pos.Y!=KL[TX[CurLvl-1]].Y||
            Path.front().Pos.X!=KL[TX[CurLvl-1]].X){
                Path.push(
                    MK(
                        Path.front().Pos,
                        Path.front().Lvl+1,
                        Path.front().Len+
                        GD(
                            KL[TX[CurLvl-1]],
                            KL[TX[CurLvl]]
                        )
                    )
                );
            }
            //---- Find Biggest OverLaping Element ----
            T=Path.front().Len+GD(Path.front().Pos,KL[TX[CurLvl]]);
            if(T<OverLap.Len){
                OverLap.Len=T;
            }
        }
        Path.push(OverLap);
    }
    //-------- Find Best Path -----------
    int res=2147483647;
    while(!Path.empty()){
        if(Path.front().Len<res){
            res=Path.front().Len;
        }
        Path.pop();
    }
    return res;
}
int main(){
    int lenY,lenX,TextLen;
    scanf("%d%d",&lenY,&lenX);
    Loc KeyLoc[lenY*lenX],locL={0,0},locR={0,lenX-1};
    for(int i=0;i<lenY;i++){
        for(int j=0,T;j<lenX;j++){
            scanf("%d",&T);
            KeyLoc[T-1].Y=(lenY-1)-i;
            KeyLoc[T-1].X=j;
        }
    }
    scanf("%d",&TextLen);
    int Text[TextLen];
    for(int i=0;i<TextLen;i++){
        scanf("%d",&Text[i]);
        Text[i]--;
    }
    printf("%d",GSD(TextLen,Text,locL,locR,KeyLoc));
    return 0;
}