#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        void nextPermutation(vector<int>& nums) {
            int i = 0;
            for(i = nums.size() - 2; i >= 0; i--)
            {
                if (nums[i] < nums[i+1]) //找到升序拐点
                {
                    break;
                } 
            }

            if(i == -1) reverse(nums.begin(), nums.end());
            else{
                for(int j = nums.size() - 1; j >= i + 1; j--)
                {
                    if(nums[i] < nums[j])
                    {
                     swap(nums[i], nums[j]);
                     reverse(nums.begin() + i + 1, nums.end());
                     break;
                    }
                }
            }
    }
};

int main()
{
    Solution solution;
    int arr[6] = {1,2,3,4,6,5};
    vector<int> nums(arr, arr+6);
    solution.nextPermutation(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ", ";
    }
    return 0;
}