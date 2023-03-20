#include<stdio.h>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;

class Graph{
    private:
        //Vertice Count
        int V;
        //Adjacency List
        vector<int> *AL;
    public:
        Graph(int &V){ 
            this->V = V;
            AL = new vector<int>[V];
        }
        void addUndirectedUnweightedEdge(int &a, int &b){
            AL[a].push_back(b);
            AL[b].push_back(a); 
        }
        int hierarchicalBFS(int &loc_sub, int &loc_sup, int &loc_exit){
            int sub_pos_count = 1, cur_time = 0;
            //Unincluded Inferior Vertices
            queue<int> OutSub;
            OutSub.push(loc_sub);
            //Unincluded Superior Vertices
            queue<int> OutSup;
            OutSup.push(loc_sup);
            //Included Inferior Vertices
            vector<int> InSub(V, INF);
            InSub[loc_sub] = 0;
            //Included Superior Vertices
            vector<int> InSup(V, INF);
            InSup[loc_sup] = 0;
            // --------- Iterate Until No More Inferior Vertices -----------
            while(sub_pos_count > 0){
                ++cur_time;
                // --------- Add Next Level Of Superior Vertices -----------
                while(!OutSup.empty() && InSup[OutSup.front()] < cur_time){
                    int s = OutSup.front();
                    OutSup.pop();
                    for(auto i : AL[s]){
                        // --------- Check If Vertice Is Included ----------
                        if(InSup[i] == INF){
                            // --- Remove Inferior Vertices That Overlap ---
                            if(InSub[i] != INF){
                                --sub_pos_count;
                            }
                            // --------- Add Next Vertice To Queue ---------
                            InSup[i] = InSup[s] + 1; 
                            OutSup.push(i);
                        }
                    }
                }
                // --------- Add Next Level Of Inferior Vertices -----------
                while(!OutSub.empty() && InSub[OutSub.front()] < cur_time){
                    int s = OutSub.front();
                    OutSub.pop();
                    for(auto i : AL[s]){
                        // --- Check If Vertice Is Included Or Overtaken ---
                        if(InSub[i] == INF && InSup[i] == INF){
                            // ---- If Inferior Reaches Exit First Stop ----
                            if(i == loc_exit){
                                return -1;
                            }
                            // ------ Keep Track Of Inferior Vertices ------
                            ++sub_pos_count;
                            // --------- Add Next Vertice To Queue ---------
                            InSub[i] = InSub[s] + 1; 
                            OutSub.push(i);
                        }
                    }
                }
            }
            return cur_time;
        }
};
int main(){
    int intersection_count;
    scanf("%d", &intersection_count);
    Graph G(intersection_count);

    int criminal_pos, officer_pos, escape_pos;
    scanf("%d %d %d", &criminal_pos, &officer_pos, &escape_pos);

    for(int i = 1, loc_x, loc_y; i < intersection_count; ++i){
        scanf("%d %d",&loc_x, &loc_y);
        G.addUndirectedUnweightedEdge(--loc_x, --loc_y);
    }

    printf("%d", G.hierarchicalBFS(--criminal_pos, --officer_pos, --escape_pos));
    return 0;
}