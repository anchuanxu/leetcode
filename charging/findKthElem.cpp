#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    int findKthElem(vector<int>& nums1, vector<int>& nums2, int k)
    {
        //assert(1 <= k <= nums1.size() + nums2.size());
        if(k <= 0 || k > nums1.size() + nums2.size())
        {
            return -1;
        }
        //在nums1中找满足i+j=k的i，同时满足nums1[i-1]<=nums2[j] && nums2[j-1]<=a[i]
        int le = max(0, int(k - nums2.size()));
        int ri = min(k, int(nums1.size()));
        while(le < ri)
        {
            int mid = le + (ri - le) / 2;
            if(nums2[k - mid - 1] > nums1[mid])
            {
                le = mid + 1;
            }
            else{
                ri = mid;
            }
        }
        cout << "le = " << le << endl;
        //循环结束,le就是所要求的位置，加上特殊情况的判断
        int nums1LeftMax = le == 0 ? INT_MIN : nums1[le - 1];
        int nums2LeftMax = le == k ? INT_MIN : nums2[k - le - 1];
        return max(nums1LeftMax, nums2LeftMax);
    }
};

int main()
{
    int arr1[5] = {1,3,5,7,9};
    int arr2[8] = {2,4,6,8,10,11,12,13};
    vector<int> ar1(arr1, arr1+5);
    vector<int> ar2(arr2, arr2+8);
    Solution solution;
    cout << solution.findKthElem(ar1, ar2, 5) << endl;
    return 0;
}