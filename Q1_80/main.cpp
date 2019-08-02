#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //首先判断数组是否为空
        if(nums.empty()) return 0;
        //当数组元素小于等于2的时候，直接返回，不做操作
        if(nums.size() <= 2) return nums.size();

        int k = 0;//指针1
        int count = 0;//计数器，当计数器的值>2的时候，k停止移动

        //开始扫描数组
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == nums[k]){
                count++;
                if(count < 2){
                    k++;
                nums[k] = nums[i];}
            }
            else
            {
               nums[++k] = nums[i];
                count=0;
            }
        }
        return k+1;
    }
};

int main() {
    int arr[] = {0,0,1,1,2,2};
    int brr[] = {0,0,1,1,1,2,2};
    int crr[] = {0,0,1,1,2,2,2,2};

    vector<int> vec_a(arr,arr+sizeof(arr)/sizeof(int));
    vector<int> vec_b(brr,brr+sizeof(brr)/sizeof(int));
    vector<int> vec_c(crr,crr+sizeof(crr)/sizeof(int));

    cout<<Solution().removeDuplicates(vec_a)<<endl;
    cout<<Solution().removeDuplicates(vec_b)<<endl;
    cout<<Solution().removeDuplicates(vec_c)<<endl;

    return 0;
}