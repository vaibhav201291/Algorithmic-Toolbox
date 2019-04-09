#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

long long max_dot_product(size_t n, vector<double> a, vector<double> b)
{
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  long long result = a[0] * b[0];

  while (n)
  {
    result += a[n] * b[n];
    n--;
  }

  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<double> a(n), b(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(n, a, b) << std::endl;
}
