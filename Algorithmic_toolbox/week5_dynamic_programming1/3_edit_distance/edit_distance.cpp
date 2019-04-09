#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
#include <math.h>


using std::string;
using namespace std;

int edit_distance(string &str1, string &str2)
{
  int len1 = str1.length() + 1;
  int len2 = str2.length() + 1;
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
        t[i][j] = j;
      }
      else if (j == 0)
      {
        t[i][j] = i;
      }
      else if (str1[i - 1] == str2[j - 1])
      {
        t[i][j] = t[i - 1][j - 1];
      }
      else
      {
        int inter = min(t[i - 1][j], t[i - 1][j - 1]);
        t[i][j] = 1 + min(inter, t[i][j - 1]);
      } 
      // cout<<t[i][j]<<" ";
        #if 0
      #endif    
    }
    // cout<<endl;
  }


  return t[len1 - 1][len2 - 1];
}

int main()
{
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str2, str1) << std::endl;
  return 0;
}
