#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;



int main()
{
    int first, len, left, right;
    cin >> first >> len >> left >> right;
    vector< vector<int> > Vec;
    Vec.push_back(vector<int>(1, first));

    for(int i = 0; i < len; ++i)
    {
        Vec.push_back(vector<int>(pow(2, i + 1)));
        for(int j = 0; j < Vec[i].size(); ++j)
        {
            if(j == Vec[i].size() - 1 && j == 0)
            {
                Vec[i + 1][0] = Vec[i][j] + left;
                Vec[i + 1].back() = Vec[i][j] + right;
                continue;
            }
            if(j == 0){
                Vec[i + 1][0] = Vec[i][j] + left;
                Vec[i + 1][((j + 1) * 2) - 0] = Vec[i][j] + right;
                continue;
            }
            if(j == Vec[i].size() - 1){
                Vec[i + 1][((j + 1) * 2) - 3] = Vec[i][j] + left;
                Vec[i + 1].back() = Vec[i][j] + right;
                continue;
            }
            Vec[i + 1][((j + 1) * 2) - 3] = Vec[i][j] + left;
            Vec[i + 1][((j + 1) * 2) - 0] = Vec[i][j] + right;
        }
    }

    for(int i = 0; i < len; ++i)
    {
        //cout << ((Vec.back().size() / pow(2, i + 1)) + 1) << " " << ((Vec[i].size() * ((Vec.back().size() / pow(2, i + 1)) + 1))) 
        //<< " " << (Vec.back().size() * 2) << " " <<((Vec.back().size() * 2) - ((Vec[i].size() * ((Vec.back().size() / pow(2, i + 1)) + 1)))) << endl;
        
        for(int u = 0; u < ((Vec[len - 1].size() * 2) - ((Vec[i].size() * ((Vec.back().size() / pow(2, i + 1)) + 1)) - (Vec.back().size() / pow(2, i + 1)))) / 2; ++u)
        {
                cout << " ";
        }
        for(int j = 0; j < Vec[i].size(); ++j)
        {
            cout << Vec[i][j];
            for(int k = 0; k < Vec.back().size() / (pow(2, i + 1)); ++k)
            {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}