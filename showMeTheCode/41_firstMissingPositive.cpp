#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        for(int i = 0; i < length; ++i)
        {
            if(nums[i] <= 0)
            {
                nums[i] = length + 1;
            }
        }
        for(int i = 0; i < length; ++i)
        {
            int num = abs(nums[i]);
            if(num <= length)
            {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for(int i = 0; i < length; ++i)
        {
            if(nums[i] > 0)
            {
                return i + 1;
            }
        }
        return length + 1;
    }
};