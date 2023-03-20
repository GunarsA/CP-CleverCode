#include<iostream>
#define LLI long long int

using namespace std;

LLI squaresInRightTriangle(LLI len_y, LLI len_x)
{
    if(len_y > len_x)
    {
        return (((len_x - 1) * len_x) / 2) + squaresInRightTriangle(len_y - len_x, len_x);
    }
    if(len_y < len_x)
    {
        return (((len_y - 1) * len_y) / 2) + squaresInRightTriangle(len_y, len_x - len_y);
    }
    return ((len_y - 1) * len_x) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    LLI len_y, len_x, batch_size;

    cin >> len_y >> len_x >> batch_size;

    squaresInRightTriangle(len_y, len_x) % batch_size ?
    cout << batch_size - (squaresInRightTriangle(len_y, len_x) % batch_size):
    cout << 0;

    return 0;
}