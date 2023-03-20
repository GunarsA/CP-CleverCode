#include<algorithm>
#include<iostream>
#include<iomanip>
#include<vector>
#include<map>

#define LD long double
#define PII pair<int, int>
#define F first
#define S second
#define INF 0x3f3f3f3f

using namespace std;

struct Matrix
{
    private:

        vector< pair<PII, int> > Triangles;

        static bool cmp_lowest(const pair<PII, int> &a, const pair<PII, int> &b)
        {
            return a.F.S < b.F.S;
        }

        inline LD getArea(multimap<int, int> &M)
        {
            LD area = 0;

            int curr_end = -INF;
            for(auto &i : M)  
            {  
                if(curr_end > i.F)  
                {  
                    if(curr_end < (i.F + i.S))
                    {
                        area += (LD)((i.F + i.S) - curr_end);
                        curr_end = (i.F + i.S);
                    }
                }  
                else
                { 
                    curr_end = (i.F + i.S);
                    area += (LD)((LD)(i.S) - 0.5);
                }  
            }

            return area;
        }

        inline void decreaseArea(multimap<int, int> &M)
        {
            for(auto i = M.begin(); i != M.end();)
            {
                if(i->S > 1)
                {
                    --(i++)->S;
                }
                else
                {
                    M.erase(i++);
                }
            }

            return;
        }

    public:

        Matrix()
        {
            int triangle_count;
            cin >> triangle_count;

            Triangles.reserve(triangle_count);
            for(int i = 0, len_x, len_y, size; i < triangle_count; ++i)
            {
                cin >> len_x >> len_y >> size;
                if(size != 0)
                {
                    Triangles.push_back({{len_x, len_y}, size});
                }
            }

            sort(Triangles.begin(), Triangles.end(), this->cmp_lowest);
        }

        inline double getSquaredArea()
        {
            LD squared_area = 0;

            multimap<int, int> Map;

            for(int i = 0, curr_height; i < (int)Triangles.size() || !Map.empty(); ++curr_height)
            {
                if(Map.empty())
                {
                    curr_height = Triangles[i].F.S;
                }

                for(; i < (int)Triangles.size() && curr_height == Triangles[i].F.S; ++i)
                {
                    Map.insert({Triangles[i].F.F, Triangles[i].S});
                }

                squared_area += getArea(Map);

                decreaseArea(Map);
            }

            return squared_area;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Matrix M;

    cout << fixed << setprecision(1) << M.getSquaredArea();

    return 0;
}