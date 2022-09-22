#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      if(matrix.empty()) return res;

      int top = 0;
      int down = matrix.size() - 1;
      int left = 0;
      int right = matrix[0].size() - 1;

      while(true)
      {
        for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
        if(++top > down) break;
        for(int i = top; i <= down; i++) res.push_back(matrix[i][right]);
        if(--right < left) break;
        for(int i = right; i >= left; i--) res.push_back(matrix[down][i]);
        if(--down < top) break;
        for(int i = down; i >= top; i--) res.push_back(matrix[i][left]);
        if(++left > right) break;
      }

      return res;
    }
};
int main() {
  Solution solution;
  vector<int> a1 = {1, 2, 3, 4};
  vector<int> a2 = {5, 6, 7, 8};
  vector<int> a3 = {9, 10, 11, 12};

  vector<vector<int>> m = {a1, a2, a3};
  vector<int> ans;
  ans = solution.spiralOrder(m);
  for(int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
