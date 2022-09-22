#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string , vector<string>> string_map;
      vector<vector<string>> res;
      if(strs.empty()) return res;

      for(auto const str : strs)
      {
        string key = str;
        sort(key.begin(), key.end());
        string_map[key].emplace_back(str);
      }

      for(auto it = string_map.begin(); it != string_map.end(); it++)
      {
        res.emplace_back(it->second);
      }
      return res;
    }
};

  //class Test{
  //public:
  //    void sortString(string string1)
  //    {
  //      cout << "sort before = " << string1 << endl;
  //      sort(string1.begin(), string1.end());
  //      cout << "sort after  = " << string1 << endl;
  //
  //      return;
  //    }
  //};

int main() {
  Solution solution;
  //  Test test;
  //  test.sortString("abcfdg");

  vector<string> strs = {"eat", "tea", "bat", "atb","ate", "acx"};
  vector<vector<string>> ans;
  ans = solution.groupAnagrams(strs);
  for(int i = 0; i < ans.size(); i++)
  {
    for(int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
