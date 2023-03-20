#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct BinaryIndexedTree{
    vector<int> BIT;
    int Len;
    BinaryIndexedTree(int Len){
        this->Len=Len+1;
        BIT.assign(Len+1,0);
    }
    BinaryIndexedTree(vector<int> V):BinaryIndexedTree(V.size()){
        for(size_t i=0;i<V.size();i++){
            Add(i,V[i]);
        }
    }
    int Sum(int R){
        int Res=0;
        for(;R>0;R-=R&(-R)){
            Res+=BIT[R];
        }
        return Res;
    }
    int Sum(int L,int R){
        return Sum(R)-Sum(L-1);
    }
    void Add(int Index,int Delta){
        for(++Index;Index<Len;Index+=Index&(-Index)){
            BIT[Index]+=Delta;
        }
    }
};
int main(){
    int lenX,lenY;
    scanf("%d%d",&lenX,&lenY);
    //------- Make A BIT Tree --------
    BinaryIndexedTree FT(lenX);
    for(int i=0;i<lenX;i++){
        FT.Add(i,1);
    }
    //------- Get X Axis Lines -------
    pair<int,int> sideX[lenX];
    for(int i=0;i<lenX;i++){
        scanf("%d",&sideX[i].first);
        sideX[i].second=i;
    }
    sort(sideX,sideX+lenX);
    //------ Get Y Axis Lines --------
    int sideY[lenY];
    for(int i=0;i<lenY;i++){
        scanf("%d",&sideY[i]);
    }
    //------- Find CrossPoints -------
    long long int res=0;
    for(int i=0,j=0;i<lenY;i++){
        for(;j<lenX&&sideX[j].first<(i+1);j++){
            long long int T=sideX[j].second;
            FT.Add(T,-1);
        }
        res+=FT.Sum(sideY[i]);
    }
    printf("%lld",res);
    return 0;
}