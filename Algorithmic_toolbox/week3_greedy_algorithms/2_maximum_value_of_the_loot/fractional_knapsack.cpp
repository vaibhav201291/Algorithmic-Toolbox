#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values)
{
  double value = 0.0;
  double n = values.size();
  double sumWeight = 0;
  vector<double> valueperweight(n);

  for (int i = 0; i < n; i++)
  {
    valueperweight[i] = values[i] / weights[i];
    sumWeight += weights[i];
    // cout << valueperweight[i] << endl;
  }
//  cout<<"tot weight "<<sumWeight<<endl;
  double vmax = 0;
  double index = 0;
  // sort(valueperweight.begin, valueperweight.end);

  while (capacity > 0 && sumWeight > 0)
  {

    for (int i = 0; i < n; i++)
    {
      if ((valueperweight[i] >= vmax) && (weights[i] > 0))
      {
        vmax = valueperweight[i];
        index = i;
        // cout << "index " << index << "vmax = " << vmax << endl;
      }
      else
      {
        // vmax =;
        // index = 0;
        // cout << "flush" << endl;
      }
    }
    if (capacity >= weights[index])
    {
      value += (valueperweight[index] * weights[index]);
      sumWeight -= weights[index];
      capacity -= weights[index];
      weights[index] = 0;
      valueperweight[index] = 0;
      vmax = 0;
      // cout << "value " << sumWeight << endl;
    }
    else
    {
      value += (valueperweight[index] * (capacity));
      sumWeight -= capacity;
      weights[index] -= (capacity);
      valueperweight[index] = 0;
      capacity = 0;
      vmax = 0;
      // cout << "value " << sumWeight << endl;
    }
  }

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;

  // int array[] = { 23, 5, -10, 0, 0, 321, 1, 2, 99, 30 };
  // size_t size = sizeof(array) / sizeof(array[0]);
  // sort(array+size, array);
  // for (size_t i = 0; i < size; ++i) {
  //    cout << array[i] << ' ';
  // }
  // cout << endl;

  return 0;
}
