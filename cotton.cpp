#include<cstdio>
#include<string>

#define GC getchar_unlocked
#define PC putchar_unlocked
#define LLI long long int
#define SIZE 1000

using namespace std;

template<typename T>
void getInt(T &x)
{
    register int c = GC();
    bool negatve = 0;
    x = 0;
    for(; (c < 48 || c > 57); c = GC());
    if(c == '-')
        {
        negatve = 1;
        c = GC();
    }
    for(; c > 47 && c < 58; c = GC())
    {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if(negatve)
    {
        x = -x;
    }
}

template<typename T>
inline void putInt(T x)
{
    string xS = to_string(x);
    for(auto i : xS)
    {
        PC(i);
    }
}

int main()
{
    int len_y, len_x, len_p;

    getInt<int>(len_y);
    getInt<int>(len_x);
    getInt<int>(len_p);

    long long int Terrain[2][SIZE + 1] = {}, res = 0;

    for(int i = 1; i <= len_y; i++)
    {
        for(int j = 1; j <= len_x; j++)
        {
            getInt<LLI>(Terrain[i % 2][j]);

            if(i + j <= len_p + 1)
            {
                Terrain[i % 2][j] += Terrain[(i - 1) % 2][j] > Terrain[i % 2][j - 1]?
                Terrain[(i - 1) % 2][j]:
                Terrain[i % 2][j - 1];
                
                if(Terrain[i % 2][j] > res)
                {
                    res = Terrain[i % 2][j];
                }
            }
        }
    }

    putInt<LLI>(res);
    return 0;
}