#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define F first
#define S second
#define ODD 1
#define EVEN 2
using namespace std;

class Graph
{
    private:
        int V;
        vector<pair<vector<int>, int> > AL;

        vector<int> biggestColoredSet(int &src)
        {
            vector<int> Independent;
            Independent.emplace_back(src);

            queue<int> Out;
            Out.push(src);

            AL[src].S = EVEN;
            while(!Out.empty())
            {
                int s = Out.front();
                Out.pop();
                for(auto i : AL[s].F)
                {
                    if(!AL[i].S)
                    {
                        if(AL[s].S == EVEN)
                        {
                            AL[i].S = ODD;
                        }
                        else{
                            AL[i].S = EVEN;
                            Independent.emplace_back(i);
                        }
                        Out.push(i);
                    }
                }
            }
            return Independent;
        }
    public:
        Graph(int &V)
        {
            this->V = V;
            AL.resize(V);
        }
        void addEdge(int &a, int &b)
        {
            AL[a].F.push_back(b);
            AL[b].F.push_back(a);
        }
        vector<int> biggestIndependentSet()
        {   
            vector<int> Set;
            for(int i = 0; i < V; ++i)
            {
                if(!AL[i].S)
                {
                    vector<int> currSet = biggestColoredSet(i);
                    Set.insert(Set.end(), currSet.begin(), currSet.end());
                }
            }
            return Set;
        }
};
int main(){
    int vertice_count;
    scanf("%d", &vertice_count);
    Graph G(vertice_count);
    for(int i = 0, tmp_1, tmp_2; i < vertice_count; ++i)
    {
        scanf("%d %d", &tmp_1, &tmp_2);
        G.addEdge(--tmp_1, --tmp_2);
    }

    vector<int> Set = G.biggestIndependentSet();
    sort(Set.begin(), Set.end());

    printf("%d\n", (int)Set.size());
    for(auto &i : Set){
        printf("%d ", ++i);
    }
    return 0;
}