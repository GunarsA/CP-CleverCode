#include<stdio.h>

#define LLI long long int
#define ULLI unsigned long long int

using namespace std;

struct NumberTree
{
    private:

        LLI route, left, right;

    public:

        NumberTree(const int &route, const int &l, const int &r): route(route), left(l), right(r){}

        LLI getNode(const ULLI len_y, const ULLI len_x)
        {
            if(len_x == 1)
            {
                return route + (len_y * left);
            }
            if(len_x == 2)
            {
                return route + ((len_y - 1) * left) + right;
            }

            if(len_y < 64)
            {
                if(len_x == ((ULLI)1 << len_y) - 1)
                {
                    return route + ((len_y - 1) * right) + left;
                }
                if(len_x == ((ULLI)1 << len_y))
                {
                    return route + (len_y * right);
                }
            }

            if(len_x & 1)
            {
                return right + getNode(len_y - 1, len_x >> 1);
            }
            else
            {
                return left + getNode(len_y - 1, (len_x >> 1) + 1);
            }
        }
};

int main()
{
    int route_value, left_weight, right_weight, cases;
    scanf("%d %d %d %d", &route_value ,&left_weight, &right_weight, &cases);

    NumberTree NT(route_value, left_weight, right_weight);

    for(LLI i = 0, tmp_1, tmp_2; i < cases; ++i)
    {
        scanf("%lld %lld", &tmp_1, &tmp_2);
        printf("%lld \n", NT.getNode(tmp_1, tmp_2));
    }

    return 0;
}