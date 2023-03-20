//KrisjanisP
//for safety use C++11
#include <bits/stdc++.h>
#define ln(a) (int)((a).length())
#define sz(a) (int)((a).size())
#define ll long long int
#define pii pair<int,int>
#define x first
#define y second
#define uns unsigned
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<pii>
#define vvi vector< vector<int> >
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF2 ((int)1e18)
#define INF 1e9
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)

//fi - first_iterator, li - last_iterator
//sort(fi, li)
//reverse(fi, li)
//*max_element(fi, li)
//*min_element(fi, li)
//accumulate(fi, li, initial_value) - returns sum
//count(fi, li, value)
//find(fi, li, value) - returns iterator
//binary_search(fi, li, value) == value
//lower_bound(fi, li, value) >=value
//upper_bound(fi, li, value) >value
//next_permutation(fi, li)
//prev_permutation(fi, li)
//distance(fi, li) - dist of iterators
//fill(fi, li, value) - fills container
//unique(fi, li) - removes duplicates

using namespace std;

struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;

    FenwickTree(ll n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(ll l, ll r) {
        return sum(r) - sum(l - 1);
    }

    void add(ll idx, ll delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    FIO;

    ll N, M;
    cin>>N>>M;
    ll a[N], b[M];
    for(ll i=0;i<N;i++) cin>>a[i];
    for(ll i=0;i<M;i++) cin>>b[i];

    FenwickTree FT(N+5);
    for(ll i=1;i<=N;i++){
        FT.add(i, 1);
    }

    //cout<<FT.sum(1, N);
    priority_queue< pair<ll,ll> > pq;
    for(ll i=0;i<N;i++){
        pq.push({-a[i], i});
    }

    ll cnt = 0;

    for(ll i=0;i<M;i++){
        while(pq.empty()==false&&(-pq.top().x)<(i+1)){
            ll v = pq.top().y;
            pq.pop();
            FT.add(v+1, -1);
        }
        cnt += FT.sum(1, b[i]);
    }
    cout<<cnt;
}