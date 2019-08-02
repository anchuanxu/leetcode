#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;//在数组arr[0...K]中保证没有重复的元素

        if (nums.empty()) return 0; //如果不进行判断数组是否为空，则会出现问题
        // error log :Line 940: Char 34: runtime error: reference binding to null pointer of type 'const value_type' (stl_vector.h)

        for(int i = 0; i < nums.size(); i++)
            if (nums[i] != nums[k]){
                k++; //需先将K往前走一步
                nums[k] = nums[i];
            }
        return k+1;

    }
};

int main() {
    int arr[] = {0,0,1,2,5};
    vector<int> vec(arr,arr + sizeof(arr)/ sizeof(int));

    //数组目前长度
    cout<<Solution().removeDuplicates(vec)<<endl;

    //数组目前的每个成员的值
    for(int i =0; i < vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}
