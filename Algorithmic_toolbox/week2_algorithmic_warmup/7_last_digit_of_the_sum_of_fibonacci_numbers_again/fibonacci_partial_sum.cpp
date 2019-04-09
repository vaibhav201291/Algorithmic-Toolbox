#include <iostream>
#include <vector>
using std::vector;

using namespace std;

int get_fibonacci_partial_sum_naive(long long x, long long n)
{
    long long fib[3];
    int flag = 1;
    long long ind = 1;
    fib[0] = 0;
    fib[1] = fib[2] = 1;
    int m = 10;
    // int modT = 0;

    while (flag && ind < (m * n))
    {
        ind++;
        if (ind < 1)
        {
            fib[2] = 0;
            // modT = (modT + fib[2]) % m;
        }
        else if (ind < 2)
        {
            fib[2] = 1;
            // modT = (modT + fib[2]) % m;
        }
        else
        {
            fib[0] = fib[1];
            fib[1] = fib[2];
            fib[2] = (fib[1] + fib[0]) % m;
            // modT = (modT + fib[2]) % m;
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
    // modT = modT - 1;
    int modInd = 0;
    int modIndF = 0;
    int modSum = 0;
    int modSumF = 0;

    if (ind > n)
    {
        modInd = n;
    }
    else
    {
        modInd = n % ind;
    }

    if (ind > x)
    {
        modIndF = x-1;
    }
    else
    {
        modIndF = (x % ind) - 1;
    }

// cout<<"Ind "<<modInd<<endl;
// cout<<"Ind from "<<modIndF<<endl;
    int mod[modInd];
    // long long modSum = 0;

    for (long long i = 0; i < modInd + 1; i++)
    {
        if (i < 2)
        {
            mod[i] = i;
            modSum = (modSum + mod[i]) % 10;
        }
        else
        {
            mod[i] = (mod[i - 1] + mod[i - 2]) % m;
            modSum = (modSum + mod[i]) % 10;
        }
    }
    // cout<<modSum<<endl;

    for (long long i = 0; i < modIndF + 1; i++)
    {
        if (i < 2)
        {
            mod[i] = i;
            modSumF = (modSumF + mod[i]) % 10;
        }
        else
        {
            mod[i] = (mod[i - 1] + mod[i - 2]) % m;
            modSumF = (modSumF + mod[i]) % 10;
        }
    }
    int last = (10 + modSum - modSumF) % 10;

    // if (x==n){
    //     cout<<"equal "<<endl;
    //     last = modSum;
    // }
    // else{
    //     cout<<"unequal "<<endl;
    //     last = modSum - modSumF;
    // }

    return last;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
