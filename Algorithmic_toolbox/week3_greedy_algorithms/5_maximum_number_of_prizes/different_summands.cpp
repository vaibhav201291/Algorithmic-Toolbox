#include <iostream>
#include <vector>

using std::vector;
using namespace std;

vector<long long> optimal_summands(int n)
{
  vector<long long> summands;
  //write your code here

  int i = 1;
  while (n)
  {
    float div = (float)n / i;
    // cout<<div<<endl;
    if (div > 2)
    {
      // if((n/i)>2){
      summands.push_back(i);
      n -= i;
      // }
      // else
      // {
      //   summands.push_back(n);
      //   n = 0;
      // }
    }
    else
    {
      summands.push_back(n);
      n = 0;
    }
    i++;
  }
  return summands;
}

int main()
{
  long long n;
  std::cin >> n;
  vector<long long> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
  cout << endl;
}
