#include<algorithm>
#include<iostream>
#include<vector>
#define LLI long long int
#define F first
#define S second

using namespace std;

bool cmp(pair< pair< int, int>, int> &a, pair< pair< int, int>, int> &b) 
{
    return a.F.F < b.F.F; 
}  
  
LLI getArea(vector< pair< pair< int, int>, int> > &Vec, int &max_h)  
{  
    LLI area = 0;

    sort(Vec.begin(), Vec.end(), cmp);  
  
    for(int height = 1; height <= max_h; ++height)
    {
        int curr_end = -1;

        for(auto &i : Vec)  
        {  
            if(i.S >= height)
            {
                if(curr_end >=  i.F.F)  
                {  
                    if(curr_end < i.F.S)
                    {
                        area += i.F.S - curr_end;
                        curr_end = i.F.S;
                    }
                }  
                else
                { 
                    curr_end = i.F.S;
                    area += curr_end - i.F.F;
                }  
            }   
        } 
    }

    return area;
}  

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int building_count, max_h = 0;
    cin >> building_count;

    vector< pair< pair< int, int>, int> > Buildings;
    Buildings.reserve(building_count);

    for(int i = 0, pos, height, width; i < building_count; ++i)
    {
        cin >> pos >> height >> width;
        Buildings.push_back({{pos, pos + width}, height});

        max_h = max(max_h, height);
    }

    cout << getArea(Buildings, max_h);

    return 0;
}