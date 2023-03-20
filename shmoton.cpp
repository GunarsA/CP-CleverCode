#include<iostream>
#include<vector>
#define LLI long long int
#define F first
#define S second
#define SIZE 100
using namespace std;

struct tile
{
    bool E;

    int YY, Y0, XX, X0;

    vector< vector<int> > V;

    tile() : E(0), YY(0), Y0(0), XX(0), X0(0)
    {
        V.resize(2, vector<int>(2, -1));
    }
};

struct gridMatrix
{
    private: 

        vector< vector< tile > > Matrix;

        void addEdge(pair<int, int> &start, pair <int, int> &end)
        {
            if(start.F == end.F)
            {
                if(start.S < end.S)
                {
                    for(int i = start.S; i <= end.S; ++i)
                    {
                        Matrix[start.F][i].E = 1;

                        if(i != start.S)
                        {
                            Matrix[start.F][i].Y0 = 1;
                        }
                        if(i != end.S)
                        {
                            Matrix[start.F][i].YY = 1;
                        }
                        
                    }
                }
                else
                {
                    for(int i = start.S; i >= end.S; --i)
                    {
                        Matrix[start.F][i].E = 1;

                        if(i != start.S)
                        {
                            Matrix[start.F][i].YY = 1;
                        }
                        if(i != end.S)
                        {
                            Matrix[start.F][i].Y0 = 1;
                        }
                    }
                }
                
                
            }
            else
            {
                if(start.F < end.F)
                {
                    for(int i = start.F; i <= end.F; ++i)
                    {
                        Matrix[i][start.S].E = 1;

                        if(i != start.F)
                        {
                            Matrix[i][start.S].X0 = 1;
                        }
                        if(i != end.F)
                        {
                            Matrix[i][start.S].XX = 1;
                        }
                    }
                }
                else
                {
                    for(int i = start.F; i >= end.F; --i)
                    {
                        Matrix[i][start.S].E = 1;

                        if(i != start.F)
                        {
                            Matrix[i][start.S].XX = 1;
                        }
                        if(i != end.F)
                        {
                            Matrix[i][start.S].X0 = 1;
                        }
                    }
                }
            }
            return;
        }

        void nextPos(pair<int, int> &CP, pair<bool, bool> &CE)
        {
            if(!Matrix[CP.F][CP.S].E)
            {
                CE.F ? ++CP.F : --CP.F;
                CE.S ? ++CP.S : --CP.S;
                return;
            }

            if(CE.F && CE.S)
            {
                if(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].X0)
                {
                    CE.F = 0; CE.S = 0;
                    --CP.F; --CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].YY)
                {
                    CE.F = 0; CE.S = 1;
                    --CP.F; ++CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].X0 && Matrix[CP.F][CP.S].XX)
                {
                    CE.F = 1; CE.S = 0;
                    ++CP.F; --CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].YY && Matrix[CP.F][CP.S].XX)
                {
                    CE.F = 0; CE.S = 0;
                    --CP.F; --CP.S;
                    return;
                }
                if((Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].XX)
                ||(Matrix[CP.F][CP.S].YY && Matrix[CP.F][CP.S].X0))
                {
                    CE.F = 1; CE.S = 1;
                    ++CP.F; ++CP.S;
                    return;
                }
            }

            if(CE.F && !CE.S)
            {
                if(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].XX)
                {
                    CE.F = 0; CE.S = 1;
                    --CP.F; ++CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].YY)
                {
                    CE.F = 0; CE.S = 0;
                    --CP.F; --CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].X0 && Matrix[CP.F][CP.S].XX)
                {
                    CE.F = 1; CE.S = 1;
                    ++CP.F; ++CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].YY && Matrix[CP.F][CP.S].X0)
                {
                    CE.F = 0; CE.S = 1;
                    --CP.F; ++CP.S;
                    return;
                }
                if((Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].X0)
                ||(Matrix[CP.F][CP.S].YY && Matrix[CP.F][CP.S].XX))
                {
                    CE.F = 1; CE.S = 0;
                    ++CP.F; --CP.S;
                    return;
                }
            }

            if(!CE.F && CE.S)
            {
                if(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].XX)
                {
                    CE.F = 1; CE.S = 0;
                    ++CP.F; --CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].YY)
                {
                    CE.F = 1; CE.S = 1;
                    ++CP.F; ++CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].X0 && Matrix[CP.F][CP.S].XX)
                {
                    CE.F = 0; CE.S = 0;
                    --CP.F; --CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].YY && Matrix[CP.F][CP.S].X0)
                {
                    CE.F = 1; CE.S = 0;
                    ++CP.F; --CP.S;
                    return;
                }
                if((Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].X0)
                ||(Matrix[CP.F][CP.S].YY && Matrix[CP.F][CP.S].XX))
                {
                    CE.F = 0; CE.S = 1;
                    --CP.F; ++CP.S;
                    return;
                }
            }

            if(!CE.F && !CE.S)
            {
                if(Matrix[CP.F][CP.S].YY && Matrix[CP.F][CP.S].XX)
                {
                    CE.F = 1; CE.S = 1;
                    ++CP.F; ++CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].YY)
                {
                    CE.F = 1; CE.S = 0;
                    ++CP.F; --CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].X0 && Matrix[CP.F][CP.S].XX)
                {
                    CE.F = 0; CE.S = 1;
                    --CP.F; ++CP.S;
                    return;
                }
                if(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].X0)
                {
                    CE.F = 1; CE.S = 1;
                    ++CP.F; ++CP.S;
                    return;
                }
                if((Matrix[CP.F][CP.S].YY && Matrix[CP.F][CP.S].X0)
                ||(Matrix[CP.F][CP.S].Y0 && Matrix[CP.F][CP.S].XX))
                {
                    CE.F = 0; CE.S = 0;
                    --CP.F; --CP.S;
                    return;
                }
            }

            return;
        }

    public:

        gridMatrix(int &edge_count)
        {
            for(int i = 0; i < SIZE; ++i)
            {
                Matrix.push_back(vector<tile>());
                for(int j = 0; j < SIZE; ++j)
                {
                    Matrix.back().push_back(tile());
                }
            }

            for(int i = 0; i < edge_count; ++i)
            {
                pair<int, int> loc_1, loc_2;
                cin >> loc_1.F >> loc_1.S >> loc_2.F >> loc_2.S;

                addEdge(loc_1, loc_2);
            }
            return;
        }

        pair<int, int> getPosAtGivenTime(pair<int, int> &src, pair<bool, bool> &energy, LLI &time)
        {
            pair<int, int> curr_p = src;
            pair<bool, bool> curr_e = energy;

            bool period = 0;

            for(LLI i = 0; i < time;)
            {
                if(Matrix[curr_p.F][curr_p.S].V[curr_e.F][curr_e.S] == -1 || period)
                {
                    if(!period)
                    {
                        Matrix[curr_p.F][curr_p.S].V[curr_e.F][curr_e.S] = i;
                    }
                    nextPos(curr_p, curr_e);

                    ++i;
                }
                else
                {
                   period = 1;

                   LLI period_len = i - (LLI)Matrix[curr_p.F][curr_p.S].V[curr_e.F][curr_e.S];
                   i += ((time - i) / period_len) * period_len;

                }
            }

            return curr_p;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pair<int, int> src;
    cin >> src.F >> src.S;

    pair<bool, bool> energy;
    int tmp;
    cin >> tmp;
    tmp == 1 ? energy.F = 1 : energy.F = 0;
    cin >> tmp;
    tmp == 1 ? energy.S = 1 : energy.S = 0;

    LLI time;
    cin >> time;

    int border_count;
    cin >> border_count;

    gridMatrix M(border_count);

    pair<int, int> end = M.getPosAtGivenTime(src, energy, time);
    cout << end.F << " " << end.S;

    return 0;
}