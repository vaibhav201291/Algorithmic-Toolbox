#include <iostream>

long long gcd_naive(long long a, long long b)
{
  // std::cout<<"hi"<<'\n';
  long long current_gcd = 1;

  if (b >= a)
  {

    if (b % a)
    {
      // std::cout<<"b high "<< b<<'\n';
      // std::cout<<"a low "<< a<<'\n';
      b %= a;
      gcd_naive(b, a);
    }
    else
    {
      // std::cout<<"a "<<a<<'\n';
      // current_gcd = a;
      return a;
    }
  }
  else
  {

    if (a % b)
    {
      // std::cout<<"a high "<<a<<'\n';
      // std::cout<<"b low "<<b<<'\n';
      a %= b;
      gcd_naive(a, b);
    }
    else
    {
      // std::cout<<"b "<<b<<'\n';
      // current_gcd = b;
      return b;
    }
  }


// for (int d = 2; d <= a && d <= b; d++) {
//   if (a % d == 0 && b % d == 0) {
//     if (d > current_gcd) {
//       current_gcd = d;
//     }
//   }
// }
// return current_gcd;
}

int main()
{
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
