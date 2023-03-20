#include<stdio.h>
#include<vector>
#include<queue>
#define F first
#define S second
#define MP make_pair
using namespace std;

struct Compare{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.F > b.F;
    }
};
int main(){
    int len;
    vector<int> Vector(2);
    priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> MinHeap;
    scanf("%d %d %d", &Vector[0], &Vector[1], &len);
    Vector.resize(len);
    MinHeap.push(MP(Vector[0] + Vector[1], 0));
    for(int i = 2; i < len; ++i){
        Vector[i] = MinHeap.top().F;
        MinHeap.push(MP(Vector[i] + Vector[i - 1], i - 1));
        while(!MinHeap.empty()){
            pair<int, int> s = MinHeap.top();
            MinHeap.pop();
            if(s.S > 0){
                MinHeap.push(MP(s.F + Vector[s.S - 1], s.S - 1));
            }
            if(s.F < MinHeap.top().F){
                break;
            }
        }
    }
    printf("%d", Vector.back());
    return 0;
}
