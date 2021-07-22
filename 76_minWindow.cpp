#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = S.size() + 1;
        int tm[256] = {0}, sm[256] = {0};
        for (int i = 0; i < T.size(); ++i) ++tm[T[i]];
        for (int right = 0; right < S.size(); ++right) {
            if (tm[S[right]] != 0) {
                ++sm[S[right]];
                if (sm[S[right]] <= tm[S[right]]) ++count;
                while (count == T.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        res = S.substr(left, minLen);
                    }
                    if (tm[S[left]] != 0) {
                        --sm[S[left]];
                        if (sm[S[left]] < tm[S[left]]) --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};


int main() {
    string str1,str2;
    str1 = "ADOBECODEBANC";
    str2 = "ABC";

    cout<<Solution().minWindow(str1,str2)<<endl;
    return 0;
}