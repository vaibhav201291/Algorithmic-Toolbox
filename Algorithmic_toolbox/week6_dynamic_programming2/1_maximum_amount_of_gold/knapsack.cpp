#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  //std::cout<<"W= "<<W<<"\n";
  //std::cout<<"Total items= "<<w.size()<<"\n";
  vector< vector<int> > matrix(w.size()+1, vector<int>(W+1,0));

  //std::cout<<"rows = "<<matrix.size()<<"\n";
  //std::cout<<"cols = "<<matrix[0].size()<<"\n";

  for (auto i=1;i<matrix.size();++i) // ith item
  {
    //std::cout<<"i="<<i<<"\n";
    for (auto j=1;j<matrix[i].size();++j) // Wi knapsack size
    {
      matrix[i][j] = matrix[i-1][j];
      if(w[i-1]<=j)
      {
        int temp_val = matrix[i-1][j-w[i-1]] + w[i-1];
        if(matrix[i][j]<temp_val)
          matrix[i][j] = temp_val; 
      }
      //std::cout<< "matrix["<<i<<"]"<<"["<<j<<"]"<<" = "<<matrix[i][j]<<" ";
      //std::cout<<matrix[i][j]<<" ";
    }
    //std::cout<<"\n";
  }

  /*int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;*/
  return matrix[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
