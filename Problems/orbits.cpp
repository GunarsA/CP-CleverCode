#include<stdio.h>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
#define F first
#define S second
using namespace std;

class FenwickTree{
    private:
        int len;
        vector<int> Vec;
    public:
        FenwickTree(int len){
            this->len = len + 1;
            Vec.assign(len + 1, 0);
        }
        void clear(){
            Vec.assign(this->len + 1, 0);
        }
        int sum(int r){
            int res = 0;
            for(;r > 0; r -= r & (-r)){
                res += Vec[r];
            }
            return res;
        }
        int sum(int l, int r){
            return sum(r) - sum(l - 1);
        }
        void add(int index, int delta){
            for(; index < len; index += index & (-index)){
                Vec[index] += delta;
            }
        }
};
bool cmp_l(pair< pair<int, int>, bool> &a, pair< pair<int, int>, bool> &b){
    if(a.F.F != b.F.F){
        return a.F.F < b.F.F;
    }
    return a.F.S < b.F.S;
}
bool cmp_r(pair< pair<int, int>, bool> &a, pair< pair<int, int>, bool> &b){
    if(a.F.S != b.F.S){
        return a.F.S < b.F.S;
    }
    return a.F.F > b.F.F;
}
int main(){
    int ellipse_count, min_size = INF, max_size = 0;
    scanf("%d", &ellipse_count);
    vector< pair< pair<int, int>, bool> > Ellipses(ellipse_count);
    for(int i = 0; i < ellipse_count; ++i){
        scanf("%d %d", &Ellipses[i].F.F, &Ellipses[i].F.S);
        max_size = max(max_size, max(Ellipses[i].F.F, Ellipses[i].F.S));
        min_size = min(min_size, min(Ellipses[i].F.F, Ellipses[i].F.S));
    }
    int amplitude = max_size - --min_size;

    long long int crosspoint_count = 0;
    int noncrossing_count = ellipse_count;
    // --------- Check Overlaps From The Left -----------
    sort(Ellipses.begin(), Ellipses.end(), cmp_l);
    FenwickTree FT(amplitude);
    for(auto &i : Ellipses){
        // - Count Crosspoints Of Ellipse From The Left -
        int curr_crosspoints = FT.sum(i.F.S - min_size, amplitude);
        crosspoint_count += curr_crosspoints;
        // ---------- Check If Has Overlaped ------------
        if(!i.S && curr_crosspoints){
            --noncrossing_count;
            i.S = 1;
        }
        // ---------- Add Ellipse To BIT Tree -----------
        FT.add(i.F.S - min_size, 1);
    }
    // -------- Check Overlaps From The Right -----------
    sort(Ellipses.begin(), Ellipses.end(), cmp_r);
    FT.clear();
    for(auto &i : Ellipses){
        // ------------ Check If Has Overlaped ----------
        if(!i.S && FT.sum(i.F.F - min_size, amplitude)){
            --noncrossing_count;
            i.S = 1;
        }
        // ---------- Add Ellipse To BIT Tree -----------
        FT.add(i.F.F - min_size, 1);
    }

    printf("%lld %d", crosspoint_count, noncrossing_count);
    return 0;
}