#include<stdio.h>
#include<vector>
#include<queue>
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

        int biggestColoredSet(int &src)
        {
            int even = 1, odd = 0;
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
                            ++odd;
                        }
                        else{
                            AL[i].S = EVEN;
                            ++even;
                        }
                        Out.push(i);
                    }
                }
            }
            return even > odd ? even : odd;
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
        int biggestIndependentSet()
        {   
            int res = 0;
            for(int i = 0; i < V; ++i)
            {
                if(!AL[i].S)
                {
                    res += biggestColoredSet(i);
                }
            }
            return res;
        }
};
int main(){
    int vertice_count, edge_count;
    scanf("%d %d", &vertice_count, &edge_count);
    Graph G(vertice_count);
    for(int i = 0, tmp_1, tmp_2; i < edge_count; ++i)
    {
        scanf("%d %d", &tmp_1, &tmp_2);
        G.addEdge(--tmp_1, --tmp_2);
    }

    printf("%d", G.biggestIndependentSet());
    return 0;
}