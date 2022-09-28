#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int left = newInterval[0];
      int right = newInterval[1];
      bool insert = false;
      vector<vector<int>> res;

      for(const auto interval : intervals)
      {
        if(interval[0] > right)
        {
          if(!insert)
          {
            res.push_back({left, right});
            insert = true;
          }
          res.push_back(interval);
        } else if(interval[1] < left)
        {
          res.push_back(interval);
        } else{
          left = min(left, interval[0]);
          right = max(right, interval[1]);
        }
      }
      if(!insert)
      {
        res.push_back({left, right});
      }

      return res;
    }
};

int main() {
  Solution solution;
  vector<vector<int>> arr{{1,3}, {2,6}, {8,9}};
  vector<vector<int>> res;
  vector<int> insert{2,7};
  res = solution.insert(arr, insert);

  for(int i = 0; i < res.size(); i++)
  {
    cout << "[ " << res[i][0] << " " << res[i][1] << " ]" << endl;
  }
  return 0;
}
