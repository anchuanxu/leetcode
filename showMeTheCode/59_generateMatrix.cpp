#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> matrix;
      matrix.resize(n);
      for(int i = 0; i < n; i++)
      {
        matrix[i].resize(n);
      }

      if(n == 0) return matrix;

      int top = 0;
      int down = n - 1;
      int left = 0;
      int right = n - 1;
      int index = 1;

      while(index <= n * n)
      {
        for(int i = left; i <= right; i++)
          matrix[top][i] = index++;
        if(++top > down) break;
        for(int i = top; i <= down; i++)
          matrix[i][right] = index++;
        if(--right < left) break;
        for(int i = right; i >= left; i--)
          matrix[down][i] = index++;
        if(--down < top) break;
        for(int i = down; i >= top; i--)
          matrix[i][left] = index++;
        if(++left > right) break;
      }

      return matrix;
    }
};

int main() {
  Solution solution;

  vector<vector<int>> res;

  res = solution.generateMatrix(3);
  for(int i = 0; i < res.size(); i++)
  {
    for(int j = 0; j < res[i].size(); j++)
    {
      cout << res[i][j] << " ";
    }
  }
  return 0;
}
