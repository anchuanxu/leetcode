//
// Created by 传旭 on 2021/7/7.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
            return s;
        int maxLen = 1;
        int begin = 0;

        vector<vector<int>> dp(n, vector<int>(n));

        //初始化，所有长度为1的字符串都是回文字符串;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        //先枚举字串长度
        for (int L = 2; L <= n ; L++) { //注意边界
            //左边界
            for (int i = 0; i < n; ++i) {
                //右边届 j - i + 1 = L
                int j = L + i - 1;
                //右边越界 则退出循环
                if (j >= n) //注意边界
                    break;
                //判断当下字符串d[i][j]是不是回文串
                if (s[i] != s[j])
                    dp[i][j] = false;
                else{
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                //只要此时dp[i][l]是回文，那就说明s[i][l]是回文，记录此时字串的长度和开始位置
                if (dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen); //阶段性拷贝函数，可以截取字符串的某个字串，参数就是开始Index和长度
    }
};

int main()
{
    Solution solution;
    string string1;
    cout << "Please enter a string = ";
    cin >> string1;
    cout << "The longest palidrome is " << solution.longestPalindrome(string1) << endl;
    return 0;
}
