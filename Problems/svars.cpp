#include<stdio.h>
#define SIZE 100000
#define LLI long long

using namespace std;

int Left_lane[SIZE],
    Right_lane[SIZE];
LLI Left_sum[SIZE + 1],
    Right_sum[SIZE + 1];

LLI BinarySearchLeftMost(LLI l, LLI r, LLI Arr[], LLI x){
    LLI m;
    while(l < r)
    {
        m = (l + r) / 2;
        if(Arr[m] < x){
            l = m + 1;
        }
        else
        {
            r = m;
        }

    }
    return l;
}
int main(){
    LLI len_l, len_r, quest_count;
    scanf("%lld %lld %lld", &len_l, &len_r, &quest_count);
    
    Left_sum[0] = 0;
    Right_sum[0] = 0;

    for(int  i = 0; i < len_l; ++i)
    {
        scanf("%d", &Left_lane[i]);
        Left_sum[i + 1] = Left_sum[i] + Left_lane[i];
    }
    for(int  i = 0; i < len_r; ++i)
    {
        scanf("%d", &Right_lane[i]);
        Right_sum[i + 1] = Right_sum[i] + Right_lane[i];
    }
    for(int i = 0; i < quest_count; ++i)
    {
        LLI pos;
        scanf("%lld", &pos);

        LLI l = 0,
        r = pos + 1;
        bool found = 0;
        while(l <= r)
        {
            LLI l_idx = (l + r) / 2,
            l_cycles = (l_idx - 1) / len_l,
            l_sum = (l_cycles * Left_sum[len_l]) + Left_sum[(l_idx - 1) % len_l],
            r_cycles = l_sum / Right_sum[len_r],
            r_sum = (r_cycles * Right_sum[len_r]),
            r_idx = BinarySearchLeftMost(0, len_r + 1, Right_sum, (l_sum - r_sum));
            r_idx += (r_cycles * len_r);
            if(l_idx + r_idx < pos)
            {
                l = l_idx + 1;
            }
            else if(l_idx + r_idx > pos)
            {
                r = l_idx - 1;
            }
            else
            {
                printf("K %d\n", Left_lane[(l_idx - 1) % len_l]);
                found = true;
                break;
            }

        }
        if(found)
        {
            continue;
        }

        l = 0;
        r = pos + 1;
        while(l <= r)
        {
            LLI r_idx = (l + r) / 2,
            r_cycles = (r_idx - 1) / len_r,
            r_sum = (r_cycles * Right_sum[len_r]) + Right_sum[(r_idx - 1) % len_r],
            l_cycles = r_sum / Left_sum[len_l],
            l_sum = (l_cycles * Left_sum[len_l]),
            l_idx = BinarySearchLeftMost(0, len_l + 1, Left_sum, (r_sum - l_sum) + 1);
            l_idx += (l_cycles * len_l);
            if(l_idx + r_idx < pos)
            {
                l = r_idx + 1;
            }
            else if(l_idx + r_idx > pos)
            {
                r = r_idx - 1;
            }
            else
            {
                printf("L %d\n", Right_lane[(r_idx - 1) % len_r]);
                break;
            }
        }
    }
    return 0;
}