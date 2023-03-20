#include<iostream>
#include<vector>
#include<bitset>
#define F first
#define S second
#define MAXSIZE 100
#define MAXTIME 1000

using namespace std;

bool allSet(vector< bitset<MAXSIZE + 4> > RectBitset, const pair<int, int> &pos_1, const pair<int, int> &pos_2, int unset_count)
{
    for(int i = pos_1.S - 1; i <= pos_1.S + 1; ++i)
    {
        for(int j = pos_1.F - 1; j <= pos_1.F + 1; ++j)
        {
            if(i == pos_1.S || j == pos_1.F)
            {
                if(RectBitset[i][j])
                {
                    --unset_count;
                    RectBitset[i][j] = 0;
                }
            }
        }
    }

    for(int i = pos_2.S - 1; i <= pos_2.S + 1; ++i)
    {
        for(int j = pos_2.F - 1; j <= pos_2.F + 1; ++j)
        {
            if(i == pos_2.S || j == pos_2.F)
            {
                if(RectBitset[i][j])
                {
                    --unset_count;
                    RectBitset[i][j] = 0;
                }
            }
        }
    }

    if(unset_count)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool canSet(vector< pair<int, int> > &Vec)
{
    if(Vec.empty())
    {
        return 1;
    }
    vector< bitset<MAXSIZE + 4> > RectBitset(MAXSIZE + 4);

    for(int i = 0; i < (int)Vec.size(); ++i)
    {
        if(RectBitset[Vec[i].S += 2][Vec[i].F += 2] == 0)
        {
            RectBitset[Vec[i].S].set(Vec[i].F);
        }
        else
        {
            Vec.erase(Vec.begin() + i);
        }
    }

    if(Vec.size() > 10)
    {
        return 0;
    }

    for(int i = 0; i < (int)Vec.size(); ++i)
    {
        pair<int, int> ii = Vec[i];
        for(--ii.S; ii.S <= Vec[i].S + 1; ++ii.S)
        {
            for(ii.F = Vec[i].F - 1; ii.F <= Vec[i].F + 1; ++ii.F)
            {
                if(ii.S == Vec[i].S || ii.F == Vec[i].F)
                {
                    for(int j = i; j < (int)Vec.size(); ++j)
                    {
                        pair<int, int> jj = Vec[j];
                        for(--jj.S; jj.S <= Vec[j].S + 1; ++jj.S)
                        {
                            for(jj.F = Vec[j].F - 1; jj.F <= Vec[j].F + 1; ++jj.F)
                            {
                                if(jj.S == Vec[j].S || jj.F == Vec[j].F)
                                {
                                    if(allSet(RectBitset, ii, jj, (int)Vec.size()))
                                    {
                                        return 1;
                                    }
                                }   
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int size, time;
    cin >> size >> time;

    bitset<MAXTIME> CanSet;

    for(int i = 0, set_count; i < time; ++i)
    {
        cin >> set_count;

        vector< pair<int, int> > Vec;
        Vec.reserve(set_count);
        
        while(--set_count >= 0)
        {
            pair<int, int> Loc;
            cin >> Loc.S >> Loc.F;
            Vec.emplace_back(Loc);
        }
        if(canSet(Vec))
        {
            CanSet.set(i);
        }
    }

    cout << CanSet.count() << endl;
    for(int i = 0; i < time; ++i)
    {
        cout << CanSet[i] << endl;
    }

    return 0;
}
