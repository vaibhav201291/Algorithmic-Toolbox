#include <iostream>

using namespace std;

long long get_change(long long m)
{
  //write your code here
  // int nCoins = 0;
  long long c10 = 0;
  long long c5 = 0;
  long long c1 = 0;

  while (m)
  {
    if (m / 10)
    {
      c10 = m / 10;
      m = m - (c10 * 10);
    }
    else if (m / 5)
    {
      c5 = m / 5;
      m = m - (c5 * 5);
    }
    else
    {
      c1 = m / 1;
      m = m - (c1 * 1);
    }
  }

  // cout<<"c10 "<<c10<<endl;
  // cout<<"c5 "<<c5<<endl;
  // cout<<"c1 "<<c1<<endl;
  

  return c10 + c5 + c1;
}

int main()
{
  long long m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
