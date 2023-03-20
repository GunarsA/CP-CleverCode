#include<algorithm>
#include<iostream>
#include<vector>
#define INF 0x3f3f3f3f

using namespace std;

inline int modifiedKadanesAlgorithm(const vector<int> &Full, const vector<int> &Top, const vector<int> &Bottom)
{
    int max_sum = Full[0] + Full[1],
    curr_sum = Full[0] + Full[1];

    for(int i = 2; i < (int)Full.size(); ++i)
    {
        int prev_mid = Full[i - 1] - (Top[i - 1] + Bottom[i - 1]);
        
        if(curr_sum - prev_mid > Full[i - 1])
        {
            curr_sum += Full[i] - prev_mid;
        }
        else
        {
            curr_sum = Full[i] + Full[i - 1];
        }

        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

inline int maxPerimeter(const vector< vector<int> > &Matrix)
{
    int max_sum = -INF;

    for(int top = 0; top < (int)Matrix.size() - 1; ++top)
    {
        vector<int> CurrDepthSum(Matrix[top].begin(), Matrix[top].end());

        for(int bottom = top + 1; bottom < (int)Matrix.size(); ++bottom)
        {
            for(int i = 0; i < (int)Matrix[bottom].size(); ++i)
            {
                CurrDepthSum[i] += Matrix[bottom][i];
            }

            max_sum = max(max_sum, modifiedKadanesAlgorithm(CurrDepthSum, Matrix[top], Matrix[bottom]));
        }
    }

    return max_sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int len_x, len_y;
    cin >> len_y >> len_x;

    vector< vector<int> > Matrix;
    Matrix.reserve(len_y);

    for(int i = 0; i < len_y; ++i)
    {
        Matrix.emplace_back(vector<int>());
        Matrix.back().reserve(len_x);

        for(int j = 0, tmp; j < len_x; ++j)
        {
            cin >> tmp;

            Matrix.back().emplace_back(tmp);
        }
    }

    cout << maxPerimeter(Matrix);

    return 0;
}