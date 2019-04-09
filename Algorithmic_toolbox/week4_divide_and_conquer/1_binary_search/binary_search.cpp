#include <iostream>
// #include <cassert>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

long long binary_search(const vector<long long> &a, long long x, long long startp, long long endp)
{
  long long left = startp;
  long long right = endp;
  // cout << "start:   " << startp << endl;
  // cout << "end:    " << endp << endl;

  long long center = left + ((right - left) / 2);
  // cout << "Center :" << center << endl;

  // cout<<"serach fo :   "<< x << endl;
  // cout<<"center ele:   "<<a[center]<<endl;

  if (x > a[center] && x <= a[right])
  {
    left = center + 1;
    binary_search(a, x, left, right);
  }
  else if (x < a[center] && x >= a[left])
  {
    right = center - 1;
    binary_search(a, x, left, right);
  }
  else if (x == a[center])
  {
    return center;
  }
  else
  {
    return -1;
  }
}

long long linear_search(vector<long long> &a, long long x)
{

  cout << "size : " << a.size() << endl;
  for (size_t i = 0; i < 15; ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  long long m;
  std::cin >> m;
  vector<long long> b(m);
  for (long long i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }

  long long startp, endp;

  for (long long i = 0; i < m; ++i)
  {
    startp = 0;
    endp = a.size() - 1;
    std::cout << binary_search(a, b[i], startp, endp) << ' ';
  }
  cout << endl;
}
