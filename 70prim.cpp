#include<iostream>
#include<vector>
#include<queue>
#define F first
#define S second
using namespace std;

string smallestMultipleWith70(int &x)
{
    queue<pair<string, int> > Out;
    Out.push({"7", 7 % x});
    vector<bool> In(x);

    while(!Out.empty())
    {
        auto s = Out.front();
        Out.pop();
        if(s.S > 0)
        {
            if(!In[s.S])
            {   
                In[s.S] = 1;
                Out.push({s.F + '0', (s.S * 10) % x});
                Out.push({s.F + '7', ((s.S * 10) + 7) % x});
            }
        }
        else
        {
            return s.F;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    int x;
    cin >> x;
    cout << smallestMultipleWith70(x);
    return 0;
}