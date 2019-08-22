#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> record;
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                record[C[i] + D[j]] ++;
            }
        }
        int res = 0;
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                if(record.find(- A[i] - B[j]) != record.end())
                    res += record[0 - A[i] - B[j]];
            }
        }
        return res;

    }
};

int main() {
    vector<int> a = {1,2};
    vector<int> b = {-2,-1};
    vector<int> c = {-1,2};
    vector<int> d = {0,2};

    cout<<Solution().fourSumCount(a,b,c,d)<<endl;
    return 0;
}