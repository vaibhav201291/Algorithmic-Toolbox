#include <iostream>
#include <cmath>

using namespace std;

int get_change(int m)
{
  int minCoins = 0;

  int t[4][m + 1];
  int coins[4] = {0, 1, 3, 4};

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < m + 1; j++)
    {
      t[i][j] = 0;
    }
  }

  for (int i = 1; i < 4; i++)
  {
    for (int j = 1; j < m + 1; j++)
    {
      if (coins[i] == 1)
      {
        t[i][j] = j;
      }
      else
      {
        if (j >= coins[i])
        {
          t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i]]);
        }
        else
        {
          t[i][j] = t[i - 1][j];
        }
      }
    }
  }
  minCoins = t[3][m];

  return minCoins;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
