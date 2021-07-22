#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        for(int i = 0; i < nums.size(); i++){

            int conplement = target - nums[i];
            if(record.find(conplement) != record.end()){
                int res[2] ={i,record[conplement]};
                return vector<int>(res,res+2);
            }
            record[nums[i]] = i;
        }

        throw invalid_argument("the input has no solution");

    }
};

int main() {

    vector<int>  arr = {2,7,11,15};
    vector<int>  res;
    res = Solution().twoSum(arr,9);
    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}