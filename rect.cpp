#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

long long int matchingSubarrays(vector<long long int> &PrefSumArr, int &min_v, int &max_v) {
    long long int res = 0;
    int len = (int)PrefSumArr.size();
    for(int i = 0; i < len; ++i)
    {   
        auto l = lower_bound(
            PrefSumArr.begin() + i,
            PrefSumArr.end(),
            PrefSumArr[i] + min_v
        );
        auto r = upper_bound(
            PrefSumArr.begin() + i, 
            PrefSumArr.end(), 
            PrefSumArr[i] + max_v
        );
        min_v?
        res += (long long int)(r - l):
        res += (long long int)(r - (l + 1));
    }
    return res;
}
long long int matchingRectangles(vector<vector<int> > &Matrix, int &min_v, int &max_v){
    long long int res = 0;
    int len_y = (int)Matrix.size();
    int len_x = (int)Matrix.front().size();

    for(int top = 0; top < len_y; ++top)
    {
        vector<long long int> CurrRowSum(len_x + 1, 0);
        for(int bottom = top; bottom < len_y; ++bottom)
        {
            for(int i = 1, curr_sum = 0; i <= len_x; ++i)
            {   
                curr_sum += Matrix[bottom][i - 1];
                CurrRowSum[i] += curr_sum;
            }
            res += matchingSubarrays(CurrRowSum, min_v, max_v);
        } 
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int len_y, len_x, min_v, max_v;
    cin >> len_y >> len_x >> min_v >> max_v;
    vector<vector<int> >Matrix(len_y, vector<int>(len_x));

    for(auto &i : Matrix){
        for(auto &j : i){
            cin >> j;
        }
    }
    
    cout << matchingRectangles(Matrix, min_v, max_v);
    return 0;
}