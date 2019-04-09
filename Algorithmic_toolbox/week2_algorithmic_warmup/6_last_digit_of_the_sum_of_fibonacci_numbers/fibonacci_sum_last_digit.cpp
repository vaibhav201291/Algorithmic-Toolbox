#include <iostream>
using namespace std;

int fibonacci_sum_naive(long long n)
{
    long long fib[3];
    int flag = 1;
    long long ind = 1;
    fib[0] = 0;
    fib[1] = fib[2] = 1;
    int m = 10;
    int modT = 0;

    while (flag && ind < (m * n))
    {
        ind++;
        if (ind < 1)
        {
            fib[2] = 0;
            modT = (modT + fib[2]) % m;
        }
        else if (ind < 2)
        {
            fib[2] = 1;
            modT = (modT + fib[2]) % m;
        }
        else
        {
            fib[0] = fib[1];
            fib[1] = fib[2];
            fib[2] = (fib[1] + fib[0]) % m;
            modT = (modT + fib[2]) % m;
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

    cout << ind << endl;
    modT = modT - 1;
    int modInd = 0;
    int modSum = 0;
    int modQ = 0;//n/ind;

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
            modSum = (modQ * modT) + (modSum + mod[i]) % 10;
        }
        else
        {
            mod[i] = (mod[i - 1] + mod[i - 2]) % m;
            modSum = (modQ * modT) + (modSum + mod[i]) % 10;
            cout<<modSum<<endl;
        }
    }
    // cout<<modSum<<endl;

    return modSum;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n) << '\n';
}
