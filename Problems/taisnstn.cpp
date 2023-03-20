#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>

#define LD long double
#define PDD pair<LD, LD>
#define F first
#define S second

using namespace std;

struct Matrix
{
    private:

        LD len_x, len_y;

        vector<LD> RectStart;

        vector<LD> RectEnd;

        static bool cmp(const LD &a, const LD &b)
        {
            return a < b;
        }

        bool existsIntegerCrosspoint(LD &x, LD &y) const 
        {
            LD diagonal = atan2(len_y, len_x);
            LD full = atan2((LD)1, (LD)0);

            bool lower_crosses_right;
            LD lower_bound;
            if(x < diagonal)
            {
                lower_crosses_right = 1;
                lower_bound = tan(x) * len_x;
            }
            else
            {
                lower_crosses_right = 0;
                lower_bound = tan(full - x) * len_y;
            }

            bool upper_crosses_right;
            LD upper_bound;
            if(x < diagonal)
            {
                upper_crosses_right = 1;
                upper_bound = tan(y) * len_x;
            }
            else
            {
                upper_crosses_right = 0;
                upper_bound = tan(full - y) * len_y;
            }

            if(lower_crosses_right != upper_crosses_right 
            || floor(lower_bound) != floor(upper_bound)
            || floor(lower_bound) == lower_bound
            || floor(upper_bound) == upper_bound
            ){
                return 1;
            }

            return 0;
        }

    public:

        Matrix(const int &len_x, const int &len_y): len_x(len_x), len_y(len_y)
        {
            int rect_count;
            cin >> rect_count;

            RectStart.reserve(rect_count);
            RectEnd.reserve(rect_count);

            while(--rect_count >= 0)
            {
                PDD  lower_right, upper_left;
                cin >> upper_left.F >> lower_right.S >> lower_right.F >> upper_left.S;

                RectStart.push_back(atan2(lower_right.S, lower_right.F));
                RectEnd.push_back(atan2(upper_left.S, upper_left.F));
            }

            sort(RectStart.begin(), RectStart.end(), this->cmp);
            sort(RectEnd.begin(), RectEnd.end(), this->cmp);

            return;
        }

        int maxOverlap()
        {
            int res = 0;

            for(int s_pos = 0, e_pos = 0; s_pos < (int)RectStart.size();)
            {
                if(RectStart[s_pos] <= RectEnd[e_pos] 
                && existsIntegerCrosspoint(RectStart[s_pos], RectEnd[e_pos])
                ){
                    res = max(res, ++s_pos - e_pos);
                }
                else
                {
                    ++e_pos;
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
    
    int len_x, len_y;
    cin >> len_x >> len_y;

    Matrix M(len_x, len_y);

    cout << M.maxOverlap() << endl;

    return 0;
}