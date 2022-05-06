#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0;
        int r = -1;
        int res = 0;

        while(l < s.size()){

            if( r+1<s.size() && freq[s[r+1]] == 0){
                r++;
                freq[s[r]] ++;
            }
            else{
                freq[s[l]] --;
                l++;
            }

            res = max(res,r-l+1);
        }
        return res;

    }
};

class Solution2 {
public:
int lengthOfLongestSubstring(string s) {
    vector<int> m(128, 0); //ASCII码范围：0-127
    int ans = 0;
    int i = 0;
    for (int j = 0; j < s.size(); j++) {
        if(m[s[j]]!=0)  
        {
            i = max(i, m[s[j]]);
        }
        m[s[j]] = j + 1;
        ans = max(ans, j - i + 1);
    }
    return ans;
}
};

class Solution3{
    public:
    int lengthOfLongestSubstring(string s) 
    {
        int res = 0;
        unordered_set<char> window;
        int left = 0;
        for(int i = 0; i < s.size(); i++)
        {
            // find s[i] exist in window
            while(window.find(s[i]) != window.end())
            {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[i]);
            res = max(res, i-left+1);
        }
      return res;
    }
};

int main() {
    string str = "abcabcbb";
    cout<<Solution().lengthOfLongestSubstring(str)<<endl;
    return 0;
}