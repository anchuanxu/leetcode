#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> path;
      backtrack(nums, path, 0);
      return res;
    }

    void backtrack(vector<int>& nums, vector<int>& path, int start)
    {
      res.push_back(path);
      for(int i = start; i < nums.size(); i++)
      {
        path.push_back(nums[i]);
        backtrack(nums, path, i+1);
        path.pop_back();
      }
      return;
    }
};
int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = solution.subsets(nums);

  for(int i = 0; i < result.size(); i++)
  {
    cout << "{ ";
    for(int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }
    cout << "}" << endl;
  }
  return 0;
}
