#include<stdio.h>
using namespace std;

int main(){
    int yarn_length, price_count;
    scanf("%d %d", &yarn_length, &price_count);

    int BestPrice[yarn_length]{};
    for(int i = 0, tmp_1, tmp_2; i < price_count; ++i)
    {
        scanf("%d %d", &tmp_1, &tmp_2);
        if(BestPrice[--tmp_1] < tmp_2)
        {
            BestPrice[tmp_1] = tmp_2;
        } 
    }

    for(int i = 0; i < yarn_length; ++i)
    {
        for(int j = 0; j < (i + 1) >> 1; ++j)
        {
            if(BestPrice[i - j - 1] + BestPrice[j] > BestPrice[i])
            {
                BestPrice[i] = BestPrice[i - j - 1] + BestPrice[j];
            }
        }
    }

    printf("%d", BestPrice[yarn_length - 1]);
    return 0;
}