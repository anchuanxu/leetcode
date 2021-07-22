//
// Created by 传旭 on 2021/7/9.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();
        bool flag;

        for (int i = 0; i + len2 <= len1; ++i) {
            flag = true;
            for (int j = 0; j < len2; ++j) {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string haystack, needle;
    cout << "haystack = ";
    cin >> haystack;
    cout << " needle = ";
    cin >> needle;
    cout << solution.strStr(haystack, needle) << endl;
    return 0;
}