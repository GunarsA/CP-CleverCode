#include<iostream>
#include<bitset>
#include<vector>
#include<queue>
#include<array>

#define PII pair<int, int>
#define F first
#define S second
#define LOOP 10

using namespace std;

struct Matrix
{
    private:

        int len_y, len_x;

        vector< vector<char> > Terrain;

        vector< vector< bitset<LOOP> > > BackTrack;

        inline void setTile(const PII &pos, const int &rem, array< queue<PII>, LOOP > &Q)
        {
            if(
                pos.F >= len_y 
                || pos.F < 0 
                || pos.S >= len_x 
                || pos.S < 0
                || Terrain[pos.F][pos.S] == '#'
                || BackTrack[pos.F][pos.S].count() == LOOP
            ){
                return;
            }

            if(Terrain[pos.F][pos.S] == '.' 
            || Terrain[pos.F][pos.S] == 'A' 
            || Terrain[pos.F][pos.S] == 'B'
            ){
                for(int i = 0; i < LOOP; ++i)
                {
                    if(i == rem || BackTrack[pos.F][pos.S][i])
                    {
                        continue;
                    }

                    BackTrack[pos.F][pos.S].set(i);
                    Q[i].push(pos);
                }

                return;
            }

            for(int i = rem + 1;; ++i)
            {
                if(i > 9){i = 0;}

                if(
                    i == (int)(Terrain[pos.F][pos.S] - 48)
                    || i - 10 == (int)(Terrain[pos.F][pos.S] - 48)
                ){
                    break;
                }

                if(BackTrack[pos.F][pos.S][i])
                {
                    continue;
                }

                BackTrack[pos.F][pos.S].set(i);
                Q[i].push(pos); 
            }

            return;
        }

        inline void errorCheckTile(const PII &pos, const int &rem, array< queue<PII>, LOOP > &Q)
        {
            if(Terrain[pos.F][pos.S] == '.' && !BackTrack[pos.F][pos.S][rem > 0? rem - 1: 9])
            {
                BackTrack[pos.F][pos.S].set(rem > 0? rem - 1: 9);
                Q[rem > 0? rem - 1: 9].push(pos);
            }

            return;
        }

    public:

        Matrix()
        {
            cin >> len_y >> len_x;
            Terrain.resize(len_y, vector<char>(len_x));
            BackTrack.resize(len_y, vector< bitset<LOOP> >(len_x));

            for(auto &i : Terrain)
            {
                for(auto &j : i)
                {
                    cin >> j;
                }
            }
        }

        inline int findPath()
        {
            array< queue<PII>, LOOP > Queue;

            for(int i = 0; i < len_y; ++i)
            {
                for(int j = 0; j < len_x; ++j)
                {
                    if(Terrain[i][j] == 'A')
                    {
                        setTile({i, j}, -1, Queue);
                    }
                }
            }

            int curr_time = 0;

            for(;; ++curr_time)
            {
                int curr_rem = curr_time % 10;

                while(!Queue[curr_rem].empty())
                {
                    PII c = Queue[curr_rem].front();

                    if(Terrain[c.F][c.S] == 'B')
                    {
                        return curr_time;
                    }

                    

                    errorCheckTile(c, curr_rem, Queue);

                    setTile({c.F + 1, c.S}, curr_rem, Queue);
                    setTile({c.F - 1, c.S}, curr_rem, Queue);
                    setTile({c.F, c.S + 1}, curr_rem, Queue);
                    setTile({c.F, c.S - 1}, curr_rem, Queue);

                    Queue[curr_rem].pop();
                }

                bool is_empty = 1;
                for(auto &i : Queue)
                {
                    if(!i.empty())
                    {
                        is_empty = 0;
                    }
                }
                if(is_empty){break;}
            }

            return 0;
        }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Matrix M;

    cout << M.findPath() << endl;

    return 0;
}