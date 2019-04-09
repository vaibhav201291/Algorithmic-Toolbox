#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

int lcs2(vector<int> &b, vector<int> &a)
{
  cout << endl;
  //write your code here
  int len1 = a.size() + 1;
  int len2 = b.size() + 1;
  int t[len1][len2];

  for (int i = 0; i < len1; i++)
  {
    for (int j = 0; j < len2; j++)
    {
      t[i][j] = 0;
    }
  }

  for (int i = 0; i < len1; i++)
  {
    for (int j = 0; j < len2; j++)
    {
      if (i == 0)
      {
        t[i][j] = 0;
      }
      else if (j == 0)
      {
        t[i][j] = 0;
      }
      else if (a[i - 1] == b[j - 1])
      {
        // int interEq = max(t[i - 1][j], t[i - 1][j - 1]);
        t[i][j] = 1 + t[i - 1][j - 1];
      }
      else
      {
        // int inter = max(t[i - 1][j], t[i - 1][j - 1]);
        t[i][j] = max(t[i][j - 1], t[i - 1][j]);
      }
      // cout << t[i][j] << " ";
#if 0
#endif
    }
    // cout << endl;
  }

  return t[len1 - 1][len2 - 1];
  // return std::min(std::min(a.size(), b.size()), c.size());
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++)
  {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
