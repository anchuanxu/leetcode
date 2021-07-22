//
// Created by 传旭 on 2021/7/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int size = nums.size(); //取长度

        if (size < 3) return {}; //特殊判断

        vector<vector<int>> res; //储存结果 是一个动态的 二维数组
        sort(nums.begin(), nums.end()); //排序

        for (int i = 0; i < size; ++i) { //第一个元素循环
            if (nums[i] > 0) return res; //第一个元素大于0的时候，不再继续搞了

            if (i > 0 && nums[i] == nums[i-1]) continue; //如果重复了 则跳过重复选项

            int left = i + 1; //左指针
            int right = size - 1; //右指针

            while (left < right) //第二遍循环
            {
                if (nums[left] + nums[right] > -nums[i]) right--; //两数和太大 右边指针缩小点
                else if (nums[left] + nums[right] < -nums[i]) left++; //两数和太小 左边指针变大点
                else{
                    res.push_back({nums[i], nums[left], nums[right]}); //找到了存起来
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) left++; //继续遍历 看看有没有其他合成形式
                    while (left < right && nums[right] == nums[right + 1]) right--; //有重复的数字 去重
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result;
    result = solution.threeSum(nums);
    for (int i = 0; i < result.size(); ++i) {
        cout << "{";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ", ";
        }
        cout << "} ";
    }
    return 0;
}