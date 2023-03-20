#include<stdio.h>
#include<vector>
#include<algorithm>
#define F first
#define S second
using namespace std;

int cmp(pair<pair<int, int >, int > &a, pair<pair<int, int >, int > &b)
{
    return a.S > b.S;
}
class Graph{
    private:
        int V;
        vector<int> Parent;
        vector<pair<pair<int, int >, int > > Edge;

        int getParent(int &x)
        {
            if(Parent[x] < 0)
            {
                return x;
            }
            return Parent[x] = getParent(Parent[x]);
        }
    public:
        Graph(int &V, int &E)
        {
            this->V = V;
            Parent.resize(V, -1);
            Edge.resize(E);

            for(auto &i : Edge)
            {
                scanf("%d %d %d" , &i.F.F, &i.F.S, &i.S);
                --i.F.F; 
                --i.F.S;
            }
            sort(Edge.begin(), Edge.end(), cmp);
        }
        int minUnionFind()
        {
            int res = 0;
            for(auto &curr_edge : Edge)
            {
                if(getParent(curr_edge.F.F) != getParent(curr_edge.F.S))
                {
                    if(Parent[getParent(curr_edge.F.F)] < Parent[getParent(curr_edge.F.S)])
                    {
                        Parent[getParent(curr_edge.F.F)] += Parent[getParent(curr_edge.F.S)];
                        Parent[getParent(curr_edge.F.S)] = curr_edge.F.F;
                    }
                    else
                    {
                        Parent[getParent(curr_edge.F.S)] += Parent[getParent(curr_edge.F.F)];
                        Parent[getParent(curr_edge.F.F)] = curr_edge.F.S;
                    }
                }
                else
                {
                    res += curr_edge.S;
                }
            }
            return res;
        }
};
int main(){
    int vertice_count, edge_count;
    scanf("%d %d", &vertice_count, &edge_count);
    Graph G(vertice_count, edge_count);

    printf("%d", G.minUnionFind());
    return 0;
}