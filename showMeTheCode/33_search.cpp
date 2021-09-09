#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;

        if(nums.size() == 1)
        {
            return nums[0] == target ? 0 : -1;
        }

        int flag;
        flag = findFlag(nums);
        cout << "flag = " << flag << endl;

        if(target > nums[flag])
        {
            return -1;
        }
        
        if(target < nums[0] )
        {
            if(flag == nums.size() - 1)
            {
                return -1;
            }
            return BinarySearchTarget(nums, flag + 1, nums.size() - 1, target);
        }
        else if(target > nums[0])
        {
            return BinarySearchTarget(nums, 0, flag, target);
        }
        else
        {
            return 0;
        }
    }
    int findFlag(vector<int>& nums)
    {
        int l, r, mid;
        l = 0;
        r = nums.size() - 1;
        if(nums[r] > nums[l])
        {
            return r;
        } //此时为升序

        while(l <= r)
        {
            mid = (l + r) / 2;
            if(mid == nums.size() - 1)
            {
                return mid;
            }

            if(nums[mid] > nums[mid + 1] && mid + 1 < nums.size())
            {
                return mid;
            }
            else if(nums[mid] < nums[mid + 1] && nums[mid] >= nums[l]){
                l = mid + 1;
            }
            else if(nums[mid] < nums[mid + 1] && nums[mid] < nums[l])
            {
                r = mid - 1;
            }
        }
        return l;
    }
    int BinarySearchTarget(vector<int>& nums, int l, int r, int target)
    {
        int mid;
        while(l <= r)
        {
            mid = (l + r) / 2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int arr[2] = {1,3};
    vector<int> nums(arr, arr+2);
    int target = 0;
    Solution solution;
    cout << solution.search(nums, target) << endl;
    return 0;
}

//leetcode经典题解
class SolutionA {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
        {
            return -1;
        }
        int n = nums.size() - 1;
        if (n == 0)
        {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[0] <= nums[mid])
            {
                // 左半边有序
                if (nums[0] <= target && target <= nums[mid])
                {
                // target的值在左半边
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                // 右半边有序
                if (nums[mid] <= target && target <= nums[n])
                {
                // target的值在右半边
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};