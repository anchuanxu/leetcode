#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution2 {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      for (int i = n - 1; i >= 0; --i) {
        if (digits[i] != 9) {
          ++digits[i];
          for (int j = i + 1; j < n; ++j) {
            digits[j] = 0;
          }
          return digits;
        }
      }

      // digits 中所有的元素均为 9
      vector<int> ans(n + 1);
      ans[0] = 1;
      return ans;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int index = digits.size();
      for(int i = digits.size() - 1; i >= 0; i--)
      {
        if(digits[i] != 9)
        {
          index = i;
          break;
        }
      }
      if(index == digits.size()) // all is 9
      {
        vector<int> res(digits.size() + 1);
        res[0] = 1;
        return res;
      }else if(index == digits.size() - 1){  // 9 not in back
        digits[digits.size() - 1] += 1;
        return digits;
      }else{ // 9 in back
        digits[index] += 1;
        for(int i = index + 1; i < digits.size(); i++)
        {
          digits[i] = 0;
        }
        return digits;
      }
    }
};

int main() {
  Solution solution;
  vector<int> arr = {1, 2, 3, 5};
  vector<int> arr2 = {1, 9, 9, 9, 9};
  vector<int> arr3 = {9, 9, 9};
  vector<int> res;
  res = solution.plusOne(arr2);
  for(int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
