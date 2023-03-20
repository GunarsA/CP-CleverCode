#include<stdio.h>
#include<vector>
#include<list>
#include<set>
#define INF 0x3f3f3f3f
#define F first
#define S second
#define MP make_pair
using namespace std;

class Graph{
    private:
        //Vertice Count
        int V;
        //Adjacency List
        pair< list< pair<int, int> >, bool> *AL;
    public:
        Graph(int &V){ 
            this->V = V;
            AL = new pair< list< pair<int, int> >, bool>[V];
            for(int i = 0; i < V; ++i){
                AL[i].S = 0;
            }
        }
        void addDirectedEdge(int &a, int &b, int &weight){
            AL[a].F.push_back(MP(b, weight)); 
        }
        void setAsSafe(int &x){
            AL[x].S = 1;
        }
        void modifiedDijkstraAlgorithm(int &start, int &end){ 
            //Distance To Unincluded Vertices
            set< pair<int, int> > Out;
            //Distance And Safety To Included Vertices
            vector< pair<int, int> > In(V, MP(INF, INF));
            In[start].F = 0;
            In[start].S = 0;
            //Parent Of Given Vertice
            vector<int> Prev(V, -1);
            for(int unsafety = 0; In[end].F == INF; ++unsafety){
                Out.insert(MP(0, start));
                while(!Out.empty()){
                    //Vertice With Smallest Distance
                    int s = (*Out.begin()).S;
                    Out.erase(Out.begin()); 
                    for(auto i : AL[s].F){
                        bool risk = 0;
                        if(!AL[i.F].S){
                            if(In[s].S >= unsafety){
                                continue;
                            }
                            risk = 1;
                        }
                        if((In[i.F].F >= In[s].F + i.S)&&
                        (In[i.F].S >= In[s].S + risk)){
                            //----------- Distance ------------
                            auto pos = Out.find(MP(In[i.F].F, i.F));
                            if(pos != Out.end()){
                                Out.erase(pos); 
                            }
                            In[i.F].F = In[s].F + i.S; 
                            Out.insert(MP(In[i.F].F, i.F));
                            //----------- Unsafety ------------
                            In[i.F].S = In[s].S + risk;
                            //------------- Path --------------
                            Prev[i.F] = s;
                        } 
                    }
                }
            }
            printf("%d %d\n",In[end].S, In[end].F);
            vector<int> Vec;
            for(int i = end; i != -1; i = Prev[i]){
                Vec.push_back(i);
            }
            for(auto i = Vec.rbegin(); i != Vec.rend(); ++i){
                printf("%d ", *i);
            }
        }
};
int main(){
    int vertice_count, 
    company_count, 
    passport_count, 
    start_vertice, 
    end_vertice;
    scanf("%d %d %d %d %d", 
        &vertice_count, 
        &company_count, 
        &passport_count, 
        &start_vertice, 
        &end_vertice
    );
    Graph G(vertice_count);
    for(int i = 0, tmp;i < company_count; ++i){
        scanf("%d", &tmp);
        for(int j = 0, loc_x, loc_y, weight; j < tmp; ++j){
            scanf("%d %d %d", &loc_x, &loc_y, &weight);
            G.addDirectedEdge(loc_x, loc_y, weight);
        }
    }
    for(int i = 0, tmp; i < passport_count; ++i){
        scanf("%d", &tmp);
        G.setAsSafe(tmp);
    }
    G.modifiedDijkstraAlgorithm(start_vertice, end_vertice);
    return 0;
}