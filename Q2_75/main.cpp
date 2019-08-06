#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//方法一：用计数器分类数字
//时间复杂度O(n)
//空间复杂度O(1)
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count[3] = {0};//存放0,1,2三个数字的频率
        //把对应的值先计数
        for(int i = 0; i < nums.size(); i++) {
            assert(nums[i] >= 0 && nums[i] <= 2);
            count[nums[i]]++;
        }

        int index = 0;//设置好索引，用来将数字放入数组

        for(int i = 0; i < count[0]; i++){
            nums[index++] = 0;
        }
        for(int i = 0; i < count[1]; i++){
            nums[index++] = 1;
        }
        for(int i = 0; i < count[2]; i++){
            nums[index++] = 2;
        }
    }
};
 */
//方法二：三路快速排序，只需要遍历一遍数组
//时间复杂度O(n)
//空间复杂度O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1;// 定义左边的指针，并且赋值-1,最终nums[0 ... zero] = 0；
        int two = nums.size(); //定义右边的指针，并且赋值为nums.size(),最终
        //nums[two ... nums.size()-1] = 2；

        for(int i = 0; i < two; ){// 部分场景i不需要移动，所以第三个语句空置。
            assert(nums[i] >= 0 && nums[i] <= 2);
            if(nums[i] ==  1)
                i++;
            else if(nums[i] == 2){
                two--;
                swap(nums[i],nums[two]);
            } else{
                zero++;
                swap(nums[i++],nums[zero]);
            }

        }

    }
};

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    vector<int> vec(arr, arr + sizeof(arr)/ sizeof(int));
    Solution().sortColors(vec);
    for(int i = 0; i < n; i++)
        cout<<vec[i];
    cout<<endl;
    return 0;
}