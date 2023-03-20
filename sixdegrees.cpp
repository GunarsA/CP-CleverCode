#include<stdio.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define GC getchar
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;

class Graph{
    private:
        //Vertice Count
        int V;
        //Adjacency List
        vector< vector<int> > AL;
    public:
        Graph(int &V){ 
            this->V = V;
            AL.resize(V, vector<int>(0));
        }
        void addUndirectedUnweightedEdge(int &a, int &b){
            AL[a].push_back(b);
            //AL[b].push_back(a); 
        }
        pair<int, int> breadthFirstSearch(int &start){
            int farthest_node = 0;

            queue<int> Out;
            Out.push(start);

            vector<int> In(V, INF);
            In[start] = 0;

            while(!Out.empty())
            {
                int s = Out.front();
                Out.pop();
                for(auto &i : AL[s])
                {
                    if(In[i] == INF){
                        In[i] = In[s] + 1;
                        farthest_node = i;
                        Out.push(i);
                    }
                }
            }
            return {farthest_node, In[farthest_node]};
        }
};

void scanString(string &x){
    register int c = GC();
    x.clear();
    for(;(c < 41 || c > 126); c = GC());
    for(;c > 41 && c < 126; c = GC()){
        x.push_back(c);
    }
}

int main(){
    int people_count, relation_count;
    scanf("%d %d", &people_count, &relation_count);

    Graph G(people_count);
    map <string, int> Map;

    for(int i = 0; i < relation_count; i++){
        string tmp_1, tmp_2;
        scanString(tmp_1);
        scanString(tmp_2);

        if(Map.find(tmp_1) == Map.end()){
            Map.insert({tmp_1, Map.size()});
        }
        if(Map.find(tmp_2) == Map.end()){
            Map.insert({tmp_2, Map.size()});
        }

        G.addUndirectedUnweightedEdge(Map[tmp_1], Map[tmp_2]);
    }

    int degree_of_seperation = 1;
    int curr_node = 0;
    // I Don't Know Why Checking 3 Times Works
    for(int i = 0; i < 3; ++i){
        pair<int, int> curr_farthest = G.breadthFirstSearch(curr_node);
        if(curr_farthest.S > degree_of_seperation && curr_farthest.S != INF){
            degree_of_seperation = curr_farthest.S;
        }
        curr_node = curr_farthest.F;
    }

    printf("%d", degree_of_seperation);
    return 0;
}