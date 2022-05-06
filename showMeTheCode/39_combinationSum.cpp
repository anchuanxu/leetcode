#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, 0, target);
        return res;
    }

    void dfs(vector<int>& c, int u, int target)
    {
        if(target < 0) return;
        if(target == 0)
        {
            res.emplace_back(path);
            return;
        }
        for(int i = u; i < c.size(); i++)
        {
            if(c[i] <= target)
            {
                path.emplace_back(c[i]);
                dfs(c, i, target-c[i]);
                path.pop_back();
            }
        }
    }
};