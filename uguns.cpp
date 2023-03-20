#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
#define F first
#define S second

using namespace std;

struct Matrix
{
    private:

        int len_y, len_x;

        vector< vector<char> > Terrain;

        vector< vector<int> > FireSpread;

        bool checkFirePosition(int &pos_y, int &pos_x, int &weight)
        {
            if(
                pos_y >= 0 && pos_y < len_y
                && pos_x >= 0 && pos_x < len_x
                && Terrain[pos_y][pos_x] != 'X' 
                && Terrain[pos_y][pos_x] != 'H'
                && FireSpread[pos_y][pos_x] == INF
            ){
                FireSpread[pos_y][pos_x] = weight + 1;
                return 1;
            }
            return 0;
        }

        bool checkEscapePosition(int &pos_y, int &pos_x, vector< vector<bool> > &Check)
        {
            if(
                pos_y >= 0 && pos_y < len_y
                && pos_x >= 0 && pos_x < len_x 
                && Terrain[pos_y][pos_x] != 'X'
                && !Check[pos_y][pos_x]
            ){
                return 1;
            }
            return 0;
        }

    public:

        Matrix(int &len_y, int &len_x)
        {
            this->len_y = len_y;
            this->len_x = len_x;

            Terrain.resize(len_y, vector<char>(len_x));
            FireSpread.assign(len_y, vector<int>(len_x, INF));
        }

        void getInput()
        {
            for(auto &i : Terrain)
            {
                for(auto &j : i)
                {
                    cin >> j;
                }
            }
        }

        void fillFireSpread()
        {
            queue< queue< pair<int, int> > > Queue;
            Queue.push(queue< pair<int, int> >());

            for(int i = 0; i < len_y; ++i)
            {
                for(int j = 0; j < len_x; ++j)
                {
                    if(Terrain[i][j] == 'F')
                    {
                        FireSpread[i][j] = 0;
                        Queue.back().push({i, j});
                    }
                }
            }

            while(!Queue.front().empty())
            {
                Queue.push(queue< pair<int, int> >());

                while(!Queue.front().empty())
                {
                    auto f = Queue.front().front();
                    
                    for(int i = f.F - 1; i <= f.F + 1; ++i)
                    {
                        for(int j = f.S - 1; j <= f.S + 1; j++)
                        {
                            if(checkFirePosition(i, j, FireSpread[f.F][f.S]))
                            {
                                Queue.back().push({i, j});
                            }
                        }
                    }

                    Queue.front().pop();
                }

                Queue.pop();
            }
        }

        int fillEscapeTime()
        {
            int can_escape = 0;

            vector< vector< pair<int, int> > > LastTime(len_y * len_x, vector< pair<int, int> >());
            vector< vector<bool> > Escapable(len_y, vector<bool>(len_x, 0));

            for(int i = 0; i < len_y; ++i)
            {
                for(int j = 0; j < len_x; ++j)
                {
                    if(Terrain[i][j] == 'H')
                    {
                        Escapable[i][j] = 1;
                        LastTime[(len_x * len_y) - 1].push_back({i, j});
                    }
                }
            }

            for(int i = (len_y * len_x) - 1; i >= 0; --i)
            {
                for(auto &f : LastTime[i])
                {

                    if(Terrain[f.F][f.S] == '+')
                    {
                        ++can_escape;
                    }
                    
                    for(int j = f.F - 1; j <= f.F + 1; ++j)
                    {
                        for(int k = f.S - 1; k <= f.S + 1; ++k)
                        {
                            if(j != f.F && k != f.S)
                            {
                                continue;
                            }
                            if(checkEscapePosition(j, k, Escapable))
                            {
                                if(min(i, FireSpread[j][k]) - 1 >= 0)
                                {   
                                    LastTime[min(i, FireSpread[j][k]) - 1].push_back({j, k});
                                    Escapable[j][k] = 1;
                                }
                            }
                        }
                    }
                }
            }

            for(int i = 0; i < len_y; ++i)
            {
                for(int j = 0; j < len_x; ++j)
                {
                    if(
                        Terrain[i][j] == '+' 
                        && FireSpread[i][j] == INF 
                        && !Escapable[i][j]
                    ){
                        ++can_escape;
                    }
                }
            }

            return can_escape;
        }
};

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int len_y, len_x;
    cin >> len_y >> len_x;

    Matrix M(len_y, len_x);

    M.getInput();

    M.fillFireSpread();

    cout << M.fillEscapeTime();

    return 0;
}