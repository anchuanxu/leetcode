#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        assert(k > 0);

        //统计nums数组中每个元素出现的频率
        unordered_map<int,int> freq;
        for(int i = 0; i < nums.size(); i++)
            freq[nums[i]] ++;

        assert(k <= freq.size());

        //扫描数组，维护当前出现频率最高的K个元素
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;//频率 元素

        for(unordered_map<int,int>::iterator iter = freq.begin();
            iter != freq.end(); iter++){
            if(pq.size() == k){
                if(iter->second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(iter->second,iter->first));
                }
            }
            else
                pq.push(make_pair(iter->second,iter->first));

        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

int main() {

    vector<int> vec;
    int x;
    int k;

    do
    {
        cin>>x;
        vec.push_back(x);
    }while(cin.get() != '\n');

    cin>>k;
    vector<int> res;
    res = Solution().topKFrequent(vec,k);

    for(int i = 0; i < res.size(); i++)
        cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}