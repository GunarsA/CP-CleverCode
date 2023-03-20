#include<unordered_map>
#include<iostream>
#include<vector>
#define LLI long long int
#define F first
#define S second

using namespace std;

struct hash_pair
{ 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2> &x) const
    { 
        auto lhs = hash<T1>{}(x.first); 
        auto rhs = hash<T2>{}(x.second); 
        
        lhs ^= rhs + 0x517cc1b727220a95 + (lhs << 6) + (lhs >> 2);
        return lhs;
    } 
}; 

struct Matrix
{
    private:

        int len_y, len_x;

    public:

        Matrix(int &len_y, int &len_x)
        {
            this->len_y = len_y;
            this->len_x = len_x;
        }

        void printBorderCounts(int &count)
        {
            unordered_map< pair<int, int>, int, hash_pair> Field;

            vector<LLI> Border(9, 0);
            Border[0] = (LLI)len_y * (LLI)len_x;

            for(int i = 0, loc_y, loc_x; i < count; ++i)
            {
                cin >> loc_y >> loc_x;

                for(int j = loc_y - 1; j <= loc_y + 1; ++j)
                {
                    for(int k = loc_x - 1; k <= loc_x + 1; ++k)
                    {
                        if(j > 0 && j <= len_y && k > 0 && k <= len_x)
                        {
                            auto curr_point = Field.find({j, k});
                            short int curr_borders = 0;
                            if(curr_point != Field.end())
                            {
                                curr_borders = curr_point->S;
                            }

                            if(j == loc_y && k == loc_x)
                            {
                                if(curr_point != Field.end())
                                {
                                    --Border[curr_borders];
                                }
                                else
                                {
                                    --Border[0];
                                }
                                Field[{j, k}] = 0;
                                continue;
                            }
                            
                            if(curr_point == Field.end())
                            {
                                Field[{j, k}] = 1;
                                --Border[0];
                                ++Border[1];
                            }
                            else if(curr_point->S != 0){
                                --Border[curr_borders];
                                ++Border[curr_borders + 1];
                                ++curr_point->S;
                            }
                        }
                    }
                }
            }

            for(auto i : Border)
            {
                cout << i << " ";
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int len_y, len_x, mine_count;

    cin >> len_y >> len_x >> mine_count;

    Matrix M(len_y, len_x);

    M.printBorderCounts(mine_count);

    return 0;
}