#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void bubbling(vector<int>& nums, int n)
    {
        if (n < 2)
        {
            return ;
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (nums[j] >= nums[j + 1])
                {
                    std::swap(nums[j], nums[j + 1]); //传址操作
                }   
            }
        }
        return ;
    }
};

int main()
{
    vector<int> arr = {4, 7, 6, 5, 2, 3};
    for (int i = 0; i < 6; i++)
    {
        cout << arr.at(i) << ", ";
    }
    cout << endl;
    Solution solution;
    solution.bubbling(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr.at(i) << ", ";
    }
    return 0;
}