#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  int candidate;
  int count = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (count == 0)
    {
      candidate = a[i];
      count = 1;
    }
    else
    {
      if (a[i] == candidate)
      {
        count++;
      }
      else
      {
        count--;
      }
    }
  }

  if (count == 0)
  {
    return -1;
  }

  count = 0;
  for (int i = 0; i < a.size(); i++)
  {
    if (candidate == a[i])
    {
      count++;
    }
  }
  return (count > a.size()/2) ? candidate : -1;
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
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
