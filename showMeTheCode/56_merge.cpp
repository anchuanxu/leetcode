#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      if(intervals.size() < 2) return intervals;

      std::sort(intervals.begin(), intervals.end());
      vector<vector<int>> res;
      for(int i = 0; i < intervals.size(); i++)
      {
        int L = intervals[i][0];
        int R = intervals[i][1];
        if(!res.size() || res.back()[1] < L)
        {
          res.push_back({L, R});
        }
        else{
          res.back()[1] = max(res.back()[1], R);
        }
      }

      return res;
    }
};

int main() {
  Solution solution;
  vector<vector<int>> arr{{1,3}, {2,6}, {7,9}};
  vector<vector<int>> res;
  res = solution.merge(arr);

  for(int i = 0; i < res.size(); i++)
  {
    cout << "[ " << res[i][0] << " " << res[i][1] << " ]" << endl;
  }
  return 0;
}
