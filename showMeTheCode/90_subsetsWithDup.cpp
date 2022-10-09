#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> path;
      std::sort(nums.begin(), nums.end());
      backtrack(nums, path, 0);
      return res;
    }

    void backtrack(vector<int>& nums, vector<int>& path, int start)
    {
      res.push_back(path);
      for(int i = start; i < nums.size(); i++)
      {
        if(i > start && nums[i] == nums[i-1])
          continue;
        path.push_back(nums[i]);
        backtrack(nums, path, i+1);
        path.pop_back();
      }
      return;
    }
};
int main() {
  Solution solution;
  vector<int> nums = {1, 2, 2};
  vector<vector<int>> result = solution.subsetsWithDup(nums);

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
