#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void  quickSort(vector<int>& nums, int l, int r)
    {
        if(l >= r) return ;
        int index;

        index = quickSortPartition(nums, l, r);

        quickSort(nums, l, index - 1);
        quickSort(nums, index + 1, r);
    }
    int quickSortPartition(vector<int>& nums, int l, int r) //vector需要传引用,数组直接传递数组名字，否则,没法得到正确地址
    {
        int flag;
        flag = nums[l];
        int i, j;
        i = l;
        j = r;

        while (i < j)
        {
            while (i < j && nums[j] >= flag)
            {
                j--;
            }
            if  (i < j )
            {
                nums[i] = nums[j];
                i++; 
            }
            while (i < j && nums[i] <= flag)
            {
                i++;
            }
            if  (i < j)
            {
                nums[j] = nums[i];
                j--;
            }
        }
        nums[i] = flag;
        
        return i;
    }
};
int main()
{
    int a[6] = {4, 7, 6, 5, 2, 3};
    vector<int> arr(a, a+6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr.at(i) << ", ";
    }
    cout << endl;
    Solution solution;
    solution.quickSort(arr, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        cout << arr.at(i) << ", ";
    }
    return 0;
}