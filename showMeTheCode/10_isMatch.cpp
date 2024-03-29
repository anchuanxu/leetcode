//
// Created by 传旭 on 2021/7/13.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool match(string s, string p, int i, int j)
    {
        if (i == 0)
        {
            return false;
        }
        return p[j - 1] == '.' or s[i - 1] == p[j - 1];
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> memo(m + 1, vector<bool>(n + 1));
        memo[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] != '*')
                {
                    memo[i][j] = match(s,p,i,j) ? memo[i-1][j-1] : false; //没有*号 就正常匹配
                }
                else{
                    memo[i][j]= match(s,p,i,j-1) ? memo[i][j-2] or memo[i-1][j] : memo[i][j-2]; //有星号。见状态转移方程解析
                }
            }
        }
        return memo[m][n];
    }
};

int main()
{
    Solution solution;
    string string1, string2;
    cin >> string1;
    cin >> string2;
    cout << solution.isMatch(string1, string2) << endl;
    return 0;
}

//以一个例子详解动态规划转移方程：
//S = abbbbc
//P = ab*d*c
//1. 当 i, j 指向的字符均为字母（或 '.' 可以看成一个特殊的字母）时，
//只需判断对应位置的字符即可，
//若相等，只需判断 i,j 之前的字符串是否匹配即可，转化为子问题 f[i-1][j-1].
//若不等，则当前的 i,j 肯定不能匹配，为 false.
//
//    f[i-1][j-1]   i
//                  |
//S [a  b  b  b  b][c]
//
//P [a  b  *  d  *][c]
//                  |
//                  j
//
//
//2. 如果当前 j 指向的字符为 '*'，则不妨把类似 'a*', 'b*' 等的当成整体看待。
//看下面的例子
//
//         i
//         |
//S  a  b [b] b  b  c
//
//P  a [b  *] d  *  c
//         |
//         j
//
//注意到当 'b*' 匹配完 'b' 之后，它仍然可以继续发挥作用。
//因此可以只把 i 前移一位，而不丢弃 'b*', 转化为子问题 f[i-1][j]:
//
//      i
//      | <--
//S  a [b] b  b  b  c
//
//P  a [b  *] d  *  c
//         |
//         j
//
//另外，也可以选择让 'b*' 不再进行匹配，把 'b*' 丢弃。
//转化为子问题 f[i][j-2]:
//
//         i
//         |
//S  a  b [b] b  b  c
//
//P [a] b  *  d  *  c
//    |
//    j <--
//
//3. 冗余的状态转移不会影响答案，
//因为当 j 指向 'b*' 中的 'b' 时, 这个状态对于答案是没有用的,
//原因参见评论区 稳中求胜 的解释, 当 j 指向 '*' 时,
//dp[i][j]只与dp[i][j-2]有关, 跳过了 dp[i][j-1]