//
// Created by 传旭 on 2021/7/13.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string res = strs[0];
        for (int i = 0; i < strs.size(); ++i) {
            res = longestCommonPrefix(res, strs[i]);
            if (res == "")
                break;
        }
        return res;
    }
    string longestCommonPrefix(string string1, string string2)
    {
        int length = min(string1.size(), string2.size());
        int index = 0;
        while (index < length && string1[index] == string2[index])
        {
                index++;
        }
        return string1.substr(0,index);
    }
};

int main()
{
    Solution solution;
    vector<string> str = {"dog", "fldder", "cat"};
    cout << solution.longestCommonPrefix(str) << endl;
    return 0;
}