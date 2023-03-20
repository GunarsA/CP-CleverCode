#include<unordered_map>
#include<algorithm>
#include<string>
#include<vector>
#define GC getchar_unlocked
#define PC putchar_unlocked
#define F first
#define S second
#define PPP pair< pair<int, int>, pair<int, int> >

using namespace std;

void scanInt(int &x)
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

inline void writeInt(int x)
{
    string xS = to_string(x);
    for(auto i : xS)
    {
        PC(i);
    }
}

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

struct hash_pair_pair
{
    template <class T1, class T2, class T3, class T4>
    size_t operator()(const pair< pair<T1, T2>, pair<T3, T4> > &x) const
    {
        hash_pair HP;
        
        auto lhs = HP.operator()<T1, T2>(x.F);
        auto rhs = HP.operator()<T3, T4>(x.S);

        lhs ^= rhs + 0x517cc1b727220a95 + (lhs << 6) + (lhs >> 2);
        return lhs;
    }
};

struct Graph
{
    private:

        int len_y, len_x;

        unordered_map<PPP, int, hash_pair_pair> AL;

        inline int curLen(const PPP &a, const PPP &b)
        {
            if(AL.find(a) == AL.end())
            {
                if(
                    a.F.S - a.S.S > len_y - a.F.S
                    || a.S.F - a.F.F >= a.F.F
                    || a.S.S - a.F.S >= a.F.S
                )
                {
                    if(
                        b.S.S - b.F.S > len_y - b.S.S
                        || b.S.F - b.F.F > len_x - b.S.F
                        || b.F.S - b.S.S >= b.S.S
                    )
                    {
                        return 3;
                    }
                    else
                    {
                        AL[b] = 3;
                    }
                }
            }
            else
            {
                if
                (
                    b.S.S - b.F.S > len_y - b.S.S
                    || b.S.F - b.F.F > len_x - b.S.F
                    || b.F.S - b.S.S >= b.S.S
                )
                {
                    int tmp = AL[a] + 1;

                    AL.erase(a);

                    return tmp;
                }
                else
                {
                    AL[b] = AL[a] + 1;

                    AL.erase(a);
                }
            }

            return 0;
        }

    public:

        Graph(const int &len_x, const int &len_y)
        {
            this->len_x = len_x;
            this->len_y = len_y;
        }

        int maxPath(const int &SC)
        {
            int max_path = 0;

            vector< pair<int, int> > Vec(SC);
            unordered_map< pair<int, int>, bool, hash_pair> HashTable;

            for(int i = 0; i < SC; ++i)
            {
                scanInt(Vec[i].S);
                scanInt(Vec[i].F);
                HashTable[{Vec[i].F, Vec[i].S}] = 1;
            }

            sort(Vec.begin(), Vec.end());

            for(int i = 0; i < SC; ++i)
            {
                for(int j = i + 1; j < SC && Vec[j].F + (Vec[j].F - Vec[i].F) <= len_x; ++j)
                {
                    if(HashTable.find({Vec[j].F + (Vec[j].F - Vec[i].F), Vec[j].S + (Vec[j].S - Vec[i].S)}) != HashTable.end())
                    {
                        max_path = max(max_path, curLen({Vec[i], Vec[j]}, {Vec[j], {Vec[j].F + (Vec[j].F - Vec[i].F), Vec[j].S + (Vec[j].S - Vec[i].S)}}));
                    }
                }
            }

            return max_path;
        }
};

int main()
{
    int len_x, len_y, stomped_count;
    scanInt(len_y);
    scanInt(len_x);
    scanInt(stomped_count);

    Graph G(len_x, len_y);

    writeInt(G.maxPath(stomped_count));

    return 0;
}
