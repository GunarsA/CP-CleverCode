#include<algorithm>
#include<iostream> 
#include<vector> 

using namespace std;
  
int LongestNondecreasingSubsequence(const vector<int>& Vec)  
{  
    int max_len = 1;

    vector<int> tail(Vec.size(), 0);  
    tail[0] = Vec[0];  
      
    for(int i = 1; i < (int)Vec.size(); ++i) 
    {  
        auto l = tail.begin(), r = tail.begin() + max_len; 
        auto mid = upper_bound(l, r, Vec[i]);  
              
        if(mid == tail.begin() + max_len)
        {
            tail[max_len++] = Vec[i];  
        }
        else
        {
            *mid = Vec[i]; 
        } 
    }  
  
    return max_len;  
}  
  
int main() 
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int len;
    cin >> len;

    vector<int> Vec;
    Vec.reserve(len);

    for(int i = 0, tmp; i < len; ++i)
    {
        cin >> tmp;
        Vec.emplace_back(tmp);
    }

    cout << LongestNondecreasingSubsequence(Vec); 
    
    return 0; 
} 