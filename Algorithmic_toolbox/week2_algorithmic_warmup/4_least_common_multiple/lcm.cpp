#include <iostream>

long long lcm_naive(long long a, long long b) {
  // for (long l = 1; l <= (long long) a * b; ++l)
  //   if (l % a == 0 && l % b == 0)
  //     return l;

  // return (long long) a * b;

    // std::cout<<"hi"<<'\n';
  // long long current_gcd = 1;
  

  if (b >= a)
  {

    if (b % a)
    {
      // std::cout<<"b high "<< b<<'\n';
      // std::cout<<"a low "<< a<<'\n';
      b %= a;
      lcm_naive(b, a);
    }
    else
    {
      // std::cout<<"a "<<a<<" "<<A<<" "<< B<<'\n';
      // current_gcd = a;
      return (a);
    }
  }
  else
  {

    if (a % b)
    {
      // std::cout<<"a high "<<a<<'\n';
      // std::cout<<"b low "<<b<<'\n';
      a %= b;
      lcm_naive(a, b);
    }
    else
    {
      // std::cout<<"b "<<b<<" "<<A/a<<" "<< B/b<<'\n';
      // current_gcd = b;
      return (b);
    }
  }

}

int main() {
  long long a, b;
  std::cin >> a >> b;
  long long A = a;
  long long B = b;
  long long gcd_ab = lcm_naive(a,b);
  std::cout << gcd_ab*(A/gcd_ab)*(B/gcd_ab) << std::endl;
  return 0;
}
