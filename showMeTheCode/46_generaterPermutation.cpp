#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<bool> use;
    void generaterPermutation(const vector<int>& nums, int index, vector<int>& p){
        if(index == nums.size()){
            res.push_back(p);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!(use[i])){
                //将nums[i]添加在P中
                p.push_back(nums[i]);
                use[i] = true;
                generaterPermutation(nums, index+1,p);
                p.pop_back();
                use[i] = false;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        if(nums.size() == 0)
            return res;
        use = vector<bool>(nums.size(),false);
        vector<int> p;
        generaterPermutation(nums,0,p);

        return res;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}