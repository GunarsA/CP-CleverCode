#include<algorithm>
#include<stdio.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;

class Graph{
    private:
        int V;
        list< pair<int, int> > *AL;
        map<int, map<int, int> > AM;
        bool allPathsFound(vector<bool> &Found, vector<int> &Needed){
            for(auto i : Needed){
                if(!Found[i]){
                    return false;
                }
            }
            return true;
        }
        void DijkstraAlgorithm(int &src, vector<int> &N){ 
            //Distance To Unincluded Vertices
            set< pair<int, int> > Out;
            Out.insert(
                make_pair(0, src)
            ); 
            //Distance To Included Vertices
            vector<int> In(V,INF);
            In[src] = 0; 
            //Check Included Vertices
            vector<bool> Check(V,0);
            while(!Out.empty()){
                //Get Vertice With Smallest Distance
                int s = (*Out.begin()).second; 
                Out.erase(Out.begin()); 
                for(auto i : AL[s]){ 
                    int v = i.first; 
                    int weight = i.second; 
                    if(In[v] > In[s] + weight) { 
                        if(In[v] != INF){
                            Out.erase(
                                Out.find(
                                    make_pair(In[v], v)
                                )
                            ); 
                        }
                        In[v] = In[s] + weight; 
                        Out.insert(
                            make_pair(In[v], v)
                        ); 
                    } 
                }
                //Add Shortest Path To Adjacency Matrix
                if(find(N.begin(), N.end(), s) != N.end()){
                    AM[src][s]=In[s];
                    AM[s][src]=In[s];
                }
                Check[s]=1;
                //Check If All Needed Paths Found
                if(allPathsFound(Check,N)){
                    break;
                }
            }
        }
        void shortestPaths(vector <int> N){
            for(int i = N.size() - 1; i >= 0; --i){
                DijkstraAlgorithm(N[i], N);
                N.pop_back();
            }
        }
        int HeldKarp(int BitMask, int CurPos, int EndPos, vector< vector<int> > &DP, vector< vector<int> > &AM){
            if(BitMask == (1 << (int)AM.size()) -1){
                return AM[CurPos][EndPos];
            }
            if(DP[BitMask][CurPos] != -1){
                return DP[BitMask][CurPos];
            }
            int Ans = INF;
            for(int i = 0; i < (int)AM.size(); ++i){
                if((BitMask & (1 << i)) == 0){
                    Ans = min(Ans, AM[CurPos][i] + HeldKarp(BitMask | (1 << i), i, EndPos, DP, AM));
                }
            }
            return DP[BitMask][CurPos] = Ans;
        }
    public:
        Graph(int &V){ 
            this->V = V;
            AL = new list< pair<int, int> >[V];
        }
        void addUndirectedEdge(int &a, int &b, int &len){
            AL[a].push_back(make_pair(b, len)); 
            AL[b].push_back(make_pair(a, len)); 
        }
        int shortestHamiltonianPath(vector <int> &N){
            int Start=0,End=(int)N.size();
            shortestPaths(N);
            //Convert Adjacency Map To Adjacency Matrix
            vector< vector<int> > AM;
            for(auto i : this->AM){
                AM.push_back(vector<int>(0));
                for(auto j : i.S){
                    AM.back().push_back(j.S);
                }
                //Find Location Of Start And End Nodes
                if(i.F==N.front()){
                    Start=(int)AM.size()-1;
                }
                if(i.F==N.back()){
                    End=(int)AM.size()-1;
                }
            }
            //Make Dynamic Programming Matrix
            vector< vector<int> > DP(1 << (int)AM.size(), vector<int>(AM.size(), -1));
            return HeldKarp((1 << Start) | (1 << End), Start, End, DP, AM);
        }
};
int main(){
    int VerticeCount,MustVisitCount,EdgeCount,StartNode,EndNode;
    scanf("%d %d %d",&VerticeCount,&MustVisitCount,&EdgeCount);
    //------- Store Vertices That Must Be Visted ----------
    vector<int> MV(MustVisitCount);
    for(int i = 0; i < MustVisitCount; ++i){
        scanf("%d", &MV[i]);
        MV[i]--;
    }
    //----------- Insert First Node Of Path ---------------
    scanf("%d", &StartNode);
    StartNode--;
    if(find(MV.begin(), MV.end(), StartNode) != MV.end()){
        MV.erase(find(MV.begin(), MV.end(), StartNode));
    }
    MV.insert(MV.begin(), StartNode);
    //----------- Insert Last Node Of Path -----------------
    scanf("%d", &EndNode);
    EndNode--;
    if(find(MV.begin(), MV.end(), EndNode) != MV.end()){
        MV.erase(find(MV.begin(), MV.end(), EndNode));
    }
    MV.push_back(EndNode);
    //-------------------- Make Graph ----------------------
    Graph G(VerticeCount);
    for(int i = 0, NodeX, NodeY ,Weight; i < EdgeCount; ++i){
        scanf("%d %d %d", &NodeX, &NodeY, &Weight);
        G.addUndirectedEdge(--NodeX, --NodeY, Weight);
    }
    printf("%d",G.shortestHamiltonianPath(MV));
    return 0;
}