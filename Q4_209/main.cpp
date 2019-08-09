#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //用滑动窗口来解决该问题
        int l = 0;
        int r = -1;
        int sum = 0;
        int res = nums.size() + 1;
        //初始滑动窗口内部为空

        while(l < nums.size()){
            if(r + 1 < nums.size()&& sum< s){
                r++;
                sum += nums[r];
            }
            else{
                sum -= nums[l];
                l++;
            }

            if(sum >= s)
                res = min(res, r-l+1);
        }
        if (res == nums.size() + 1) return 0;
        else return res;

    }
};

int main() {
    vector<int> vec ={2,3,1,2,4,3};
    cout<<Solution().minSubArrayLen(7,vec)<<endl;
    return 0;
}