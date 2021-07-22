//
// Created by 传旭 on 2021/7/15.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int res;
        res = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i) {
            int left = i + 1;
            int right = size - 1;
            int total;

            while (left < right)
            {
                total = nums[i] + nums[left] + nums[right];
                if (total > target) right--;
                else if (total < target) left++;
                else {
                    return total;
                }
                if (abs(res - target) > abs(total - target))
                    res = total;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int result;
    int target;
    target = 2;
    vector<int> nums = {-1, 2, 1, -4};
    result = solution.threeSumClosest(nums, target);
    cout << result << endl;
    return 0;
}