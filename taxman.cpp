#include<iostream>
#include<vector>
#include<unordered_map>
#define F first
#define S second

using namespace std;

struct hash_pair
{ 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2> &x) const
    { 
        auto hash1 = hash<T1>{}(x.first); 
        auto hash2 = hash<T2>{}(x.second); 
        return hash1 ^ hash2; 
    } 
}; 

class Graph
{
    private:

        pair< float, float > UL, LR;
        unordered_map< pair< float, float >, pair< vector< pair< float, float > >, bool > , hash_pair> AL;

    public:

        Graph(pair< float, float > &UL, pair< float, float > &LR)
        {
            this->UL = UL;
            this->LR = LR;
        }

        void addEdge(pair< float, float > &a, pair< float, float > &b)
        {
            AL[a].F.emplace_back(b);
            AL[b].F.emplace_back(a);
        }

        float getPath(pair< float, float > curr, pair< float, float > prev)
        {
            if(AL[curr].S)
            {   
                return 0.5;
            }

            float res = 0;
            if(
                curr.F == UL.F ||
                curr.F == LR.F || 
                curr.S == UL.S || 
                curr.S == LR.S
            ){   
                res = 1;
            }
            AL[curr].S = 1;

            for(auto &i : AL[curr].F)
            {   
                if(i != prev)
                {
                    res += getPath(i, curr);
                }
                
            }
            return res;
        }

        int countChunks()
        {
            int res = 0,
            independent_count = -1;

            for(auto &i : AL)
            {   
                if(!i.S.S)
                {   
                    ++independent_count;
                    res += (int)getPath(i.F, {-1001, 1001});
                }
            }
            return res - independent_count;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int edge_count;
    cin >> edge_count;

    pair< float, float > upper_left, lower_right;
    cin >> upper_left.F >> upper_left.S >> lower_right.F >> lower_right.S;

    Graph G(upper_left, lower_right);
    for(int i = 0; i < edge_count; ++i)
    {
        pair< float, float > tmp_1, tmp_2;
        cin >> tmp_1.F >> tmp_1.S >> tmp_2.F >> tmp_2.S;
        G.addEdge(tmp_1, tmp_2);
    }

    cout << G.countChunks();

    return 0;
}