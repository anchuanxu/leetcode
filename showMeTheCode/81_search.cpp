#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty()) return false;
        if(nums.size() == 1) return nums[0] == target ? true : false;
        int index = searchIndex(nums);
        cout << "index = " << index << endl;
        if(index == 0 || index == nums.size() - 1)
        {
            return searchBinary(nums, 0, nums.size() - 1, target);
        }

        if(nums[index] > target || nums[index-1] < target) return false;

        int start, end;
        if(nums[index] >= target && target < nums[nums.size()-1])
        {
            start = index;
            end = nums.size() - 1;
        }
        if(nums[0] <= target && nums[index-1] >= target)
        {
            start = 0;
            end = index - 1;
        }
        cout << "start = " << start << endl;
        cout << "end = " << end << endl;
        return searchBinary(nums, start, end, target);
    }

    int searchIndex(vector<int>& nums)
    {
        for(int i = 0; i+1 < nums.size(); i++)
        {
            if(nums[i] > nums[i+1])
            {
                return i+1;
            }
        }

        return nums.size()-1;
    }
    bool searchBinary(vector<int>& nums, int start, int end, int target)
    {
        if(nums[start] == target || nums[end] == target) return true;
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            cout << "mid = " << mid << endl;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target)
            {
                start = mid + 1;
            } else if(nums[mid] > target)
            {
                end = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3,1,1};
    cout << solution.search(nums, 2) << endl;

    return 0;
}
