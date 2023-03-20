#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>

#define F first
#define S second
#define INF 0x3f3f3f3f

using namespace std;

struct Default
{
    private:

        int len;

        int Pos(const int &zero_pos, const int &x_pos, const int &jump_len, const int grade)
        {
            return ((x_pos - zero_pos) % jump_len) + (jump_len * grade);
        }

        int CountMoves(const int &start, const int &end, const int &jump_len)
        {
            return abs(end - start) / jump_len;
        }

    public:

        Default()
        {
            cin >> len;
        }

        int Solve()
        {
            queue< vector< pair<int, int> > > DP;
            DP.push(vector< pair<int, int> >(len));

            int zero_pos;
            cin >> zero_pos;
            
            for(int i = 1, curr_pos; i < len; ++i)
            {
                DP.push(vector< pair<int, int> >(len));

                cin >> curr_pos;

                bool not_first = 0;

                for(int j = 0, k = 0, curr_min = INF; j < len; ++j)
                {
                    int curr_grade = Pos(zero_pos, curr_pos, i, j + 1);

                    for(;k < len && DP.front()[k].S < curr_grade; ++k)
                    {
                        curr_min = min(curr_min, DP.front()[k].F);
                    }
                    if(curr_min == INF)
                    {
                        DP.back()[j].F = INF;
                    }
                    else
                    {
                        if(not_first)
                        {
                            DP.back()[j].F = min(DP.back()[j - 1].F, DP.front()[k - 1].F + CountMoves(curr_pos, zero_pos + curr_grade, i));
                        }
                        else
                        {
                            DP.back()[j].F = DP.front()[k - 1].F + CountMoves(curr_pos, zero_pos + curr_grade, i);

                            not_first = 1;
                        }
                        DP.back()[j].S = curr_grade;
                    }
                }
                
                DP.pop();
            }

            int res = INF;
            for(auto &i : DP.front())
            {
                if(i.S != -2)
                {
                    res = min(res, i.F);
                }
            }
            return res;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Default D;

    cout << D.Solve();

    return 0;
}