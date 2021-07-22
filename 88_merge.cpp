#include <iostream>
#include <vector>

using namespace std;

//方法一　用新增空间来做。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3 = nums1;

        int p = 0,q = 0;
        for(int i = 0; i < nums3.size(); i++){
            if(p < m && q < n){
                if(nums1[p] <= nums2[q])
                    nums3[i] = nums1[p++];
                else
                    nums3[i] = nums2[q++];
            }
            else if(p < m && q >= n){
                nums3[i] = nums1[p++];
            }
            else if(p >= m && q < n){
                nums3[i] = nums2[q++];
            }
        }
        for(int i = 0; i < nums1.size(); i++){
            nums1[i] = nums3[i];
        }

    }
};

//方法二： 不新增空间，只利用nums1


class Solution2 {
public:
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-1, q = n-1;
        for(int k = m+n-1; k >=0; k--)
        {
            if(p >= 0 && q >=0)
            {
                if(nums1[p] >= nums2[q])
                    nums1[k] = nums1[p--];
                else
                    nums1[k] = nums2[q--];
            }
            else if(p < 0 && q >= 0)
                nums1[k] = nums2[q--];
        }
    }

};

int main() {
    int m ,n;
    cin>>m>>n;
    int arr1[m+n],arr2[n];
    for(int i = 0; i < m; i++)
        cin>>arr1[i];
    cout<<"初始化arr1结束"<<endl;
    cout<<"arr1中的元素为："<<endl;
    for(int i = 0; i < m; i++)
        cout<<arr1[i];
    cout<<endl;

    for(int i = 0; i < n; i++)
        cin>>arr2[i];
    cout<<"初始化arr2结束"<<endl;
    cout<<"arr2中的元素为："<<endl;
    for(int i = 0; i < n; i++)
        cout<<arr2[i];
    cout<<endl;

    vector<int> vec1(arr1,arr1+sizeof(arr1)/ sizeof(int));
    vector<int> vec2(arr2,arr2+sizeof(arr1)/ sizeof(int));

    //Solution().merge(vec1,m,vec2,n);
    Solution2().merge2(vec1,m,vec2,n);

    cout<<"合并的结果为： "<<endl;
    for(int i = 0; i < m+n; i++){
        cout<<vec1[i];
    }
    std::cout <<std::endl;
    return 0;
}