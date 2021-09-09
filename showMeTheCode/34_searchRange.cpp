#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return vector<int>{-1, -1};
        if (n == 1)
        {
            if(nums[0] == target)
            {
                return vector<int>{0,0};
            }
            else{
                return vector<int>{-1,-1};
            }
        }

        int l = 0; 
        int r = n - 1;
        int mid;
        while(l <= r)
        {
            mid = l + (r - l) / 2;

            if(nums[mid] == target)
            {
                break;
            }
            else if(nums[mid] > target)
            {
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(nums[mid] != target)
        {
            return vector<int>{-1,-1};
        }

        int l1, r1;
        l1 = mid - 1;
        r1 = mid + 1;
        while(l1 >= 0)
        {
            if(nums[mid] == nums[l1])
            {
                l1--;
            }
            else{
                break;
            }
        }
        while(r1 < n)
        {
            if(nums[mid] == nums[r1])
            {
                r1++;
            }
            else{
                break;
            }
        }

        return vector<int>{l1 + 1, r1 - 1};
    }
};

int main()
{
    Solution solution;
    int arr[6] = {5,7,7,8,8,10};
    vector<int> nums(arr,arr+6);
    vector<int> res;
    
    res = solution.searchRange(nums, 8);

    for(int i = 0l; i < res.size(); i++)
    {
        cout << res[i] << ",";
    }
    return 0;
}