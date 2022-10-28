#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int res = 0;
      int length = heights.size();
      stack<int> st;
      heights.push_back(0);

      for(int i = 0; i <= length; i++)
      {
        while(!st.empty() && heights[st.top()] > heights[i])
        {
          int temp = st.top();
          st.pop();
          int left = st.empty() ? -1 : st.top();
          int tems = heights[temp] * (i - left - 1);
          res = tems > res ? tems : res;
        }
        st.emplace(i);
      }

      return res;
    }
};
int main() {
  Solution solution;
  vector<int> nums = {2,1,5,6,2,3};
  cout << solution.largestRectangleArea(nums) << endl;
  return 0;
}
