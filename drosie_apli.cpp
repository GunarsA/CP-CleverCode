#include<stdio.h>
#include<vector>
using namespace std;

class FenwickTree{
    private:
        int len;
        vector<int> Vec;
    public:
        FenwickTree(int &len){
            this->len = len + 1;
            Vec.assign(len + 1, 0);
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
int main(){
    int len_a, len_b, road_count;
    scanf("%d %d %d",&len_a, &len_b, &road_count);
    vector< vector<int> > Roads(len_a, vector<int>(0));
    for(int i = 0, tmp_1, tmp_2; i < road_count; ++i){
        scanf("%d %d", &tmp_1, &tmp_2);
        Roads[tmp_1 - 1].push_back(tmp_2);
    }

    FenwickTree FT(len_b);
    long long int crosspoint_count = 0;
    for(auto &i : Roads){
        // ----- Find Crossponts Of Current Road ------
        for(auto &j : i){
            crosspoint_count += FT.sum(j + 1, len_b);
        }
        // -------- Add Past Roads To BIT Tree --------
        for(auto &j : i){
            FT.add(j, 1);
        }
    }
    printf("%lld", crosspoint_count);
    return 0;
}