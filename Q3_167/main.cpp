#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//使用对撞指针的方法。

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        assert( numbers.size() >= 2);
        int l,r;
        l = 0; r = numbers.size()-1;
        while(l < r){
            if(numbers[l] + numbers[r] == target) {
                int res[2] = {l + 1, r + 1};
                return vector<int>(res, res + 2);
            }
            else if(numbers[l] + numbers[r] < target){
                l++;
            }
            else{
                r--;
            }
        }
        throw invalid_argument("The input has no solution.");
    }
};

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    vector<int> vec(arr,arr + sizeof(arr)/ sizeof(int));
    int res[2] = {0};
    vector<int> vecres(res,res+2);
    vecres=Solution().twoSum(vec,26);
    for(int i = 0; i < 2; i++)
        cout<<vecres[i]<<endl;
    return 0;
}