//
// Created by 传旭 on 2021/7/6.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        if (n == 1) return {"()"};

        vector<vector<string>> dp(n + 1); //dp table
        dp[0] = { "" };
        dp[1] = { "()" };

        //状态转移方程
        for (int i = 2; i <= n ; ++i) {
            for (int j = 0; j < i; ++j) {
                for (string p : dp[j]) {
                    for (string q : dp[i - j - 1]) {
                        string str = "(" + p + ")" + q;
                        dp[i].push_back(str);
                    }
                }
            }
        }
        return dp[n];
    }
};
int main()
{
    Solution solution;
    vector<string> res;
    int n;
    cout << "Please enter your want how many Parenthesis = ";
    cin >>n;
    res = solution.generateParenthesis(n);
    cout << "[ ";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << "]";
    return 0;
}