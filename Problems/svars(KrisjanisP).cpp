#include <stdio.h>
#define MaxK 100000
#define MaxL 100000
#define MaxV 10000
#define lli long long
// v arr max 2*10^9
using namespace std;

int K, L, V;

int KArr[MaxK];
int LArr[MaxL];
int VArr[MaxV];

lli KSumArr[MaxK+1];
lli LSumArr[MaxL+1];

void Input(){
    KSumArr[0] = 0;
    LSumArr[0] = 0;

    scanf("%d%d%d",&K,&L,&V);

    scanf("%d",&KArr[0]);
    KSumArr[1] = KArr[0];

    for(int i=1;i<K;i++){
        scanf("%d",&KArr[i]);
        KSumArr [i+1] = KArr[i] + KSumArr[i];
    }

    scanf("%d",&LArr[0]);
    LSumArr[1] = LArr[0];

    for(int i=1;i<L;i++){
        scanf("%d",&LArr[i]);
        LSumArr [i+1] = LArr[i] + LSumArr[i];
    }

    for(int i=0;i<V;i++){
        scanf("%d",&VArr[i]);
        //VArr[i]-=2;
    }
}

lli BSLeftmost(lli l, lli r, lli a[], lli x){

    lli m;

    while(l<r){

        m = (l+r)/2;

        if(a[m] < x)

            l = m+1;

        else

            r = m;

    }

    return l;

}
int main(){

    Input();

    lli l, r;
    lli kIndex, lIndex, kCycles, lCycles;
    lli kTotalSum, lTotalSum;
    bool found;

    for(int i = 0; i < V; i++)
    {
        l = 0;
        r = VArr[i]+1;
        found = false;
        while(l <= r)
        {
            kIndex = (l + r) / 2;
            kCycles = (kIndex - 1) / K;
            kTotalSum = (kCycles * KSumArr[K]) + KSumArr[(kIndex - 1) % K];
            lCycles = kTotalSum / LSumArr[L];
            lTotalSum = (lCycles * LSumArr[L]);
            lIndex = BSLeftmost(0, L + 1, LSumArr, (kTotalSum - lTotalSum));
            lIndex += (lCycles * L);
            if(kIndex + lIndex < VArr[i])
            {
                l = kIndex + 1;
            }
            else if(kIndex + lIndex > VArr[i])
            {
                r = kIndex - 1;
            }
            else
            {
                printf("K %d\n",KArr[(kIndex - 1) % K]);
                found = true;
                break;
            }

        }
        if(found == true)
        {
            continue;
        }
        l = 0;
        r = VArr[i]+1;
        while(l <= r)
        {
            lIndex = (l + r) / 2;
            lCycles = (lIndex - 1) / L;
            lTotalSum = (lCycles * LSumArr[L]) + LSumArr[(lIndex - 1) % L];
            //this far correct
            kCycles = lTotalSum / KSumArr[K];
            kTotalSum = (kCycles * KSumArr[K]);
            kIndex = BSLeftmost(0, K + 1, KSumArr, (lTotalSum - kTotalSum) + 1);
            kIndex += (kCycles * K);
            if( kIndex+lIndex < VArr[i])
            {
                l = lIndex + 1;
            }
            else if(kIndex + lIndex > VArr[i])
            {
                r = lIndex - 1;
            }
            else
            {
                printf("L %d\n",LArr[(lIndex - 1) % L]);
                break;
            }
        }
    }
    return 0;
}