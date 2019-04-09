#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

// int MaxPairwiseProduct(const vector<int> &numbers)
// {
//   int result = 0;
//   int n = numbers.size();
//   for (int i = 0; i < n; ++i)
//   {
//     for (int j = i + 1; j < n; ++j)
//     {
//       if (numbers[i] * numbers[j] > result)
//       {
//         result = numbers[i] * numbers[j];
//       }
//     }
//   }
//   return result;
// }

long long MaxPairwiseProductFast(const vector<long long> &numbers)
{
  long long result = 0;
  int n = numbers.size();

  int max_ind1 = 0;
  for (int i = 0; i < n; ++i)
  {
    if (numbers[i] > numbers[max_ind1])
    {
      max_ind1 = i;
    }
  }

  int max_ind2 ;

  if (max_ind1 == 0)
  {
    max_ind2 = 1;
  }
  else{
    max_ind2 = 0;
  }

  for (int j = max_ind2; j < n; ++j)
  {
    if ((j != max_ind1) && (numbers[j] > numbers[max_ind2]))
    {
      max_ind2 = j;
    }
  }
  

  result = numbers[max_ind1] * numbers[max_ind2];

  return result;
}

int main()
{
  int n;

  cin >> n;
  vector<long long> numbers(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> numbers[i];
  }

  long long result = MaxPairwiseProductFast(numbers);
  cout << result << "\n";
  return 0;
}
