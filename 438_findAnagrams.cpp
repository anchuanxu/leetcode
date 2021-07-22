#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //定义一个滑动窗口
        vector<int> pv(26,0); //保存目标子串所有字符出现次数
        vector<int> sv(26,0); //保存滑动窗口所有字符出现次数
        vector<int> res;

        if(s.size() < p.size())
            return res;
        for(int i = 0; i < p.size(); i++){
            ++ pv[p[i] - 'a'];
            ++ sv[s[i] - 'a'];
        }

        if (pv == sv)
            res.push_back(0);

        for(int i = p.size(); i < s.size(); i++){
            ++ sv[s[i] - 'a'];
            -- sv[s[i - p.size()] - 'a'];
            if(sv == pv)
                res.push_back(i - p.size() + 1);
        }
        return  res;
    }

};

int main() {
    string str1,str2;
    str1 =  "cbaebabacd";
    str2 =  "abc";
    vector<int> vec;

    vec = Solution().findAnagrams(str1,str2);

    for(int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;
    return 0;
}