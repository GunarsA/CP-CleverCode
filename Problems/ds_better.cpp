#include <iostream>

#define LLI long long int

using namespace std;

LLI divisorSumUpTo(LLI &x)
{
    LLI result = 0, sqrt_floor;

    // Add sum of all the numbers that divide numbers up to x exactly i times.
    // Do it up until i is larger than square root of x because after that it
    // becomes inefficient.
    for (LLI i = 1; i * i <= x; sqrt_floor = i++)
    {
        result += ((((x / i) - (x / (i + 1))) * ((x / i) + (x / (i + 1)) + 1)) / 2) * i;
    }

    // Add sum of all the times number i is divisor of numbers up to x 
    // multiplied by i. Subtract the occurrences that already got added in the
    // previous step. 
    for (LLI i = 1; i * i < x; i++)
    {
        result += (x / i) * i;
    }

    return result;
}

int main()
{
    LLI a, b;
    cin >> a >> b;
    cout << divisorSumUpTo(b) - divisorSumUpTo(--a) << endl;

    return 0;
}