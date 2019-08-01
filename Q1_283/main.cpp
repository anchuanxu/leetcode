#include <iostream>
#include <vector>
using namespace std;

/*
 // 解法一
 // 时间复杂度O(n)
// 空间复杂度O(n)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZeroElements;

        for(int i = 0; i < nums.size();i++){
            if(nums[i])
                nonZeroElements.push_back(nums[i]);
        }
        for(int i = 0; i < nonZeroElements.size();i++){
            nums[i]=nonZeroElements[i];
        }
        for(int i = nonZeroElements.size(); i < nums.size(); i++){
            nums[i] = 0;
        }

    }
};
*/

/*
 //解法二
// 时间复杂度O(n)
// 空间复杂度O(1)
class  Solution{
public:

    void moveZeroes(vector<int>& nums){
        int k = 0;//在数组中[0...K）的元素为非零
        //遍历到i时，保证[0...i)都为非0元素，且相对位置没有发生变化
        for(int i =0; i < nums.size();i++){
            if(nums[i])
                nums[k++] = nums[i];
        }
        //将nums剩余位置全部置换为0
        for(int i = k;i < nums.size();i++)
            nums[i] = 0;
    }
};
 */
//解法三，只进行一次遍历

class  Solution{
public:

    void moveZeroes(vector<int>& nums){
        int k = 0;//在数组中[0...K）的元素为非零
        //[K..i)为0
        //遍历到i时，保证[0...i)都为非0元素，且相对位置没有发生变化

        for(int i =0; i < nums.size();i++){
            if(nums[i])
                if(i != k)
                    swap(nums[k++],nums[i]);
                else //i == k ,数组全为0
                    k++;
        }
    }
};


int main() {
    int arr[] = {0,1,3,2,0,5};
    vector<int> vec(arr,arr + sizeof(arr)/ sizeof(int));
    Solution().moveZeroes(vec);
    for(int i =0; i < vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;

    return 0;
}