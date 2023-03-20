#include<unordered_map>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#define F first
#define S second
#define LLI long long int

using namespace std;

struct BinaryTree{
    private:

        int H;

        unordered_map< LLI, pair< vector<LLI>, pair <bool, bool> > > Map;

    public:

        BinaryTree(int &height)
        {
            H = height;
        }

        void removeEdge(LLI &a)
        {
            Map[a] = {vector<LLI>(), {0, 0}};
        }

        void addEdge(LLI &a, LLI &b)
        {
            if(Map.find(a) == Map.end())
            {
                Map[a] = {vector<LLI>(), {1, 0}};
            }
            if(Map.find(b) == Map.end())
            {
                Map[b] = {vector<LLI>(), {1, 0}};
            }
            
            Map[a].F.emplace_back(b);
            for(LLI i = a / 2; i > 0; i /= 2)
            {
                if(Map.find(i) == Map.end())
                {
                    Map[i] = {vector<LLI>(), {1, 1}};
                }
                else
                {
                    if(Map[i].S.S)
                    {
                        break;
                    }
                    Map[i].S.S = 1;
                }
                
            }

            Map[b].F.emplace_back(a);
            for(LLI i = b / 2; i > 0; i /= 2)
            {
                if(Map.find(i) == Map.end())
                {
                    Map[i] = {vector<LLI>(), {1, 1}};
                }
                else
                {
                    if(Map[i].S.S)
                    {
                        break;
                    }
                    Map[i].S.S = 1;
                }
                
            }
        }

        int BFS(LLI &src)
        {
            unordered_map<LLI, bool> Check;
            Check[src] = 1;

            queue< queue<LLI> > Queue;
            Queue.push(queue<LLI>());
            Queue.back().push(src);

            LLI lowest_level = (LLI)pow(2, H - 1);
            int res = 0;

            for(bool found = 0; !found;)
            {
                Queue.push(queue<LLI>());

                while(!Queue.front().empty())
                {
                    LLI f = Queue.front().front();
                    
                    if(f == 1)
                    {
                        found = 1;
                        break;
                    }

                    if(Map.find(f) != Map.end())
                    {
                        for(auto &i : Map[f].F)
                        {
                            if(Check.find(i) == Check.end())
                            {
                                Queue.back().push(i);
                                Check[i] = 1;
                            }
                        }
                        if(Map[f].S.F && Check.find(f / 2) == Check.end())
                        {
                            Queue.back().push(f / 2);
                            Check[f / 2] = 1;
                        }
                    }
                    else if(Check.find(f / 2) == Check.end())
                    {
                        Queue.back().push(f / 2);
                        Check[f / 2] = 1;
                    }

                    if(f < lowest_level)
                    {
                        if(
                            Check.find((f * 2)) == Check.end() 
                            && Map.find((f * 2)) != Map.end() 
                            && Map[(f * 2)].S.F 
                            && Map[f].S.S
                        ){
                            Queue.back().push((f * 2));
                            Check[(f * 2)] = 1;
                        }
                        if(
                            Check.find((f * 2) + 1) == Check.end() 
                            && Map.find((f * 2) + 1) != Map.end() 
                            && Map[(f * 2) + 1].S.F 
                            && Map[f].S.S
                        ){
                            Queue.back().push((f * 2) + 1);
                            Check[(f * 2) + 1] = 1;
                        }
                    }

                    Queue.front().pop();
                }

                Queue.pop();
                ++res; 
            }

            return res;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int height, broken_count, connected_count;
    LLI start_pos;
    cin >> height >> broken_count >> connected_count >> start_pos;

    BinaryTree T(height);

    for(int i = 0; i < broken_count; ++i)
    {
        LLI tmp;
        cin >> tmp;
        T.removeEdge(tmp);
    }

    for(int i = 0; i < connected_count; ++i)
    {
        LLI tmp_1, tmp_2;
        cin >> tmp_1 >> tmp_2;
        T.addEdge(tmp_1, tmp_2);
    }

    cout << T.BFS(start_pos);

    return 0;
}