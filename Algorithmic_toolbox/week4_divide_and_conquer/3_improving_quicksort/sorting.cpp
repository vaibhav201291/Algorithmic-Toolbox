#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using std::vector;
using namespace std;

int partition2(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] <= x)
    {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int t = l + rand() % (r - l + 1);
  swap(a[l], a[t]);
  int m = partition2(a, l, r);
  int k = m;
  for (int i = l; i < k; i++)
  {
    if (a[i] == a[m])
    {
      k--;
      swap(a[i], a[k]);
    }
  }

  randomized_quick_sort(a, l, k - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
  cout << endl;
}
