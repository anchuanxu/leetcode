#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      vector<int> row(m);
      vector<int> col(n);

      for(int i = 0; i < m; i++)
      {
        for(int j = 0; j < n; j++)
        {
          if(matrix[i][j] == 0)
          {
            row[i] = col[j] = 1;
          }
        }
      }

      for(int i = 0; i < m; i++)
      {
        for(int j = 0; j < n; j++)
        {
          if(row[i] || col[j])
          {
            matrix[i][j] = 0;
          }
        }
      }

      return;
    }

};

int main() {
  Solution solution;
  return 0;
}
