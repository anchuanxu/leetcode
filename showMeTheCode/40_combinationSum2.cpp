#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
    void dfs(vector<int>& c, int u, int target)
    {
        if(target < 0)
        {
            return;
        }
        if(target == 0)
        {
            res.emplace_back(path);
        }
        for(int i = u; i < c.size(); i++)
        {
            if(i > u && c[i] == c[i-1])
            {
                continue;
            }
            if(c[i] <= target)
            {
                path.emplace_back(c[i]);
                dfs(c, i+1, target-c[i]);
                path.pop_back();
            }
        }
    }
};