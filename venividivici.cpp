#include <iostream>
#include <cmath>

using namespace std;

unsigned long long int func(long double x)
{
    for(long double i = 10; i < 1000000000000000000; i *= 10)
    {
        long double perfect_square = x * i;
        long double small = sqrt(perfect_square);
        long double big = sqrt(perfect_square + (i - 1));

        if(small == round(small))
        {
            return small * small;
        }
        if(big == round(big))
        {
            return big * big;
        }
        if(floor(small) != floor(big))
        {
            return floor(big) * floor(big);
        }
    }
    
    return 0;
}

void print_difference(string small, string big)
{
    for(unsigned int i = small.length(); i < big.length(); ++i)
    {
        cout << big[i];
    }
}

int main()
{
    unsigned long long int N;
    cin >> N;
    print_difference(to_string(N), to_string(func(N)));
    return 0;
}