#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int res;
      int length = nums.size();

      // dp[i]表示以nums[i]为结尾的连续子数组最大和
      int dp[length];
      dp[0] = nums[0];

      for(int i = 1; i < length; i++)
      {
        if(dp[i - 1] > 0)
        {
          dp[i] = dp[i - 1] + nums[i];
        }else{
          dp[i] = nums[i];
        }
      }

      res = dp[0];
      for(int i = 1; i < length; i++)
      {
        res = dp[i] > res ? dp[i] : res;
      }

      return res;
    }
};
int main() {
  Solution solution;
  vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4};
  cout << solution.maxSubArray(arr);
  return 0;
}
