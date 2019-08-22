#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> record;
        for(int i = 0 ; i < nums1.size(); i ++){
            record.insert(nums1[i]); //重复元素只会加进去一次；
        }

        set<int> resultSet;
        for(int i = 0; i < nums2.size(); i++){
            if(record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);
        }

        vector<int> resultVector;
        for(set<int>::iterator iter = resultSet.begin() ; iter != resultSet.end(); iter ++)
            resultVector.push_back(*iter);

        return resultVector;

    }
};
*/
// 精简写法
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        set<int> record(nums1.begin(),nums1.end());

        set<int> resultSet;
        for(int i = 0; i < nums2.size(); i++){
            if(record.find(nums2[i]) != record.end())
                resultSet.insert(nums2[i]);
        }

        vector<int> resultVector(resultSet.begin(),resultSet.end());

        return resultVector;

    }
};
int main() {
    vector<int> arr1 = {1,2,2,1};
    vector<int> arr2 = {2,2};
    vector<int> arr;

    arr = Solution().intersection(arr1,arr2);
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i];

    cout<<endl;
    return 0;
}