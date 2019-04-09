#include <iostream>
using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m)
{
    long long fib[3];
    int flag = 1;
    long long ind = 1;
    fib[0] = 0;
    fib[1] = fib[2] = 1;

    while (flag && ind < (m * m))
    {
        ind++;
        if (ind < 1)
        {
            fib[2] = 0;
        }
        else if (ind < 2)
        {
            fib[2] = 1;
        }
        else
        {
            fib[0] = fib[1];
            fib[1] = fib[2];
            fib[2] = (fib[1] + fib[0]) % m;
        }
        // cout << ind << " " << fib[2] << endl;
        if (fib[2] == 1 && fib[1] == 0 && ind >= 3)
        {
            flag = 0;
        }
        else
        {
            flag = 1;
        }
    }

    // ind = ind - 1;

    // cout << ind << endl;

    int modInd = 0;

    if (ind > n)
    {
        modInd = n;
    }
    else
    {
        modInd = n % ind;
    }

    int mod[modInd];
    // long long modSum = 0;

    for (long long i = 0; i < modInd + 1; i++)
    {
        if (i < 2)
        {
            mod[i] = i;
            // modSum += mod[i];
        }
        else
        {
            mod[i] = (mod[i - 1] + mod[i - 2]) % m;
            // modSum += mod[i];
        }
    }
    // cout<<modSum<<endl;

    return mod[modInd];
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';

    return 0;
}
