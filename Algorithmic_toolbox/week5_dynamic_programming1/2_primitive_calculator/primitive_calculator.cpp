#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

vector<int> optimal_sequence(int m)
{
  std::vector<int> sequence;

  int minCoins = 0;
  int coins[4] = {0, 1, 2, 3};

  int t[4][m + 1];
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < m + 1; j++)
    {
      if (i == 0)
        t[i][j] = j;
      else
        t[i][j] = 0;
    }
  }

  for (int i = 1; i < 4; i++)
  {
    for (int j = 1; j < m + 1; j++)
    {
      if (coins[i] == 1)
      {
        t[i][j] = j - 1;
      }
      else if (j == 1)
      {
        t[i][j] = 0;
      }
      else
      {
        if (j >= coins[i])
        {
          if (j % coins[i])
          {
            t[i][j] = min(t[i - 1][j], 1 + t[i][j - 1]);
            if (!(j % 2))
            {
              t[i][j] = min(t[i][j], 1 + t[i][j / 2]);
            }
          }
          else
          {
            t[i][j] = 1 + t[i][j / coins[i]];
          }
        }
        else
        {
          t[i][j] = t[i - 1][j];
        }
      }
    }
  }
  minCoins = t[3][m];
  // while (n >= 1) {
  //   sequence.push_back(n);
  //   if (n % 3 == 0) {
  //     n /= 3;
  //   } else if (n % 2 == 0) {
  //     n /= 2;
  //   } else {
  //     n = n - 1;
  //   }
  // }

  // for (int i = 0; i < 4; i++)
  // {
  //   for (int j = m-10; j < m + 1; j++)
  //   {
  //     cout << t[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // cout << minCoins << endl;
  for (int i = 0; i < minCoins + 1; i++)
  {
    sequence.push_back(m);

    if (t[3][m] == (t[3][m / 3] + 1) && !(m%3))
    {
      // cout<<m<<" ";
      m = m / 3;
      // cout<<ind<<endl;
    }
    else if (t[3][m] == (t[3][m - 1] + 1))
    {
      // cout<<m<<" ";
      m = m - 1;
      // cout<<ind<<endl;
    }
    else if(t[3][m] == 1 + t[3][m/2] && !(m%2)){
      // cout<<m<<" ";
      m = m / 2;
      // cout<<ind<<endl;
    }
    else if (t[3][m] == (t[2][m]) && !(m%2))
    {
      // cout<<m<<" ";
      m = m / 2;
      // cout<<ind<<endl;
    }
    else{
      m = m-1;
    }
  }
  // cout << endl;

  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  // cout << endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
  cout << endl;
}
