#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size();
      int n = matrix[0].size();
      int row_index = -1;

      for(int j = m - 1; j >= 0; j--)
      {
        if(target > matrix[j][0])
        {
          row_index = j;
          break;
        } else if(target == matrix[j][0])
        {
          return true;
        }
      }
      if(row_index == -1) return false;

      if(binarySearch(matrix[row_index], target))
      {
        return true;
      }

      return false;
    }

    bool binarySearch(vector<int> arr, int target)
    {
      if(arr.empty()) return false;
      int l = 0;
      int r = arr.size() - 1;
      while(l <= r)
      {
        int mid = l + (r - l) / 2;
        if(arr[mid] == target)
        {
          return true;
        } else if(arr[mid] > target)
        {
          r = mid - 1;
        } else{
          l = mid + 1;
        }
      }
      return false;
    }
};

int main() {
  Solution solution;
  return 0;
}
