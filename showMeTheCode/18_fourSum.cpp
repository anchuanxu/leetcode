//
// Created by 传旭 on 2021/7/20.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        int a, b, c, d, size;
        size = nums.size();
        if (size < 4) return res; //特判
        if (nums[0] >= 1000000000) return res; //特判

        for (a = 0; a <= size - 4; ++a) {
            if (a > 0 && nums[a - 1] == nums[a]) continue; //去重

            if (nums[a] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target) continue; //剪枝

            if (nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target) break; //剪枝

                for (b = a + 1; b <= size - 3; ++b) {
                if (b > a + 1 && nums[b - 1] == nums[b]) continue; //去重

                if (nums[a] + nums[b] + nums[b + 1] + nums[b + 2] > target) break; //剪枝

                if (nums[a] + nums[b] + nums[size - 2] + nums[size - 1] < target) continue; //剪枝

                c = b + 1;
                d = size - 1;

                while (c < d)
                {
                    if (nums[a] + nums[b] + nums[c] + nums[d] < target) c++;
                    else if (nums[a] + nums[b] + nums[c] + nums[d] > target) d--;
                    else {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]}); //找到一组结果

                        while (c < d && nums[c + 1] == nums[c]) c++; //去重
                        while (c < d && nums[d] == nums[d - 1]) d--; //去重

                        c++; //将这组结果储存完了，指针收缩
                        d--; //寻找下一组答案
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> result;
    vector<int> arr = {1,0,-1,0,-2,2};
    vector<int> arr2 = {1000000000,1000000000,1000000000,1000000000};
    result = solution.fourSum(arr,0);


    for (int i = 0; i < result.size(); ++i) {
        cout << "{";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ", ";
        }
        cout << "} ";
    }
    return 0;
}