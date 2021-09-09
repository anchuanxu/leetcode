#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        int res = n;

        while(l <= r)
        {
            mid = l + (r - l) / 2;
            if(nums[mid] >= target)
            {
                res = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return res;
    }
};

int main()
{
    int arr[4] = {1,3,5,6};
    vector<int> nums(arr, arr+4);
    Solution solution;
    cout << solution.searchInsert(nums, 7) << endl;
    return 0;
}