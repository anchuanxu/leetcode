#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int ChooseHorse(vector<int>& nums1, vector<int>& nums2){

        int minres = 2147483640;

        for(int i = 0; i < nums2.size(); i++){
                for(int j = 0; j < nums1.size(); j++) {
                    if (nums2[i] == nums1[j])
                        minres = 0;
                    else {
                        if (nums1[j] - nums2[i] > 0 && nums1[j] - nums2[i] < minres)
                            minres = nums1[j] - nums2[i];
                        else if (nums1[j] - nums2[i] < 0 && nums2[i] - nums1[j] < minres)
                            minres = nums2[i] - nums1[j];
                    }
                }
        }
        return minres;
    }
};

int main() {
    int n ,m;
    cin>>n;
    int arr1[n];
    for(int i = 0; i < n; i++)
        cin>>arr1[i];
    cin>>m;
    int arr2[m];
    for(int j = 0; j < m; j++)
        cin>>arr2[j];

    vector<int> vec_1(arr1,arr1+sizeof(arr1)/sizeof(int));
    vector<int> vec_2(arr2,arr2+sizeof(arr2)/sizeof(int));

    cout<<Solution().ChooseHorse(vec_1,vec_2)<<endl;
    return 0;
}

//第二题滑动窗口