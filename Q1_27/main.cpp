#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //本题用快慢指针来完成
        int k = 0;
        if(nums.empty()) return 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;

    }
};

int main() {
    int arr[] = {0,0,1,1,2,3};
    vector<int> vec(arr,arr + sizeof(arr)/ sizeof(int));

    std::cout << Solution().removeElement(vec,1) << std::endl;
    return 0;
}