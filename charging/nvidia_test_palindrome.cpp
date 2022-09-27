#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int getShortCharMakeToPalindrome(const string str)
  {
    int res = 0;
    int length = str.size();
    if(length == 0 || length == 1)
    {
      return res;
    }

    // 声明一个二维数组，dp[i][j]代表的是字符串s[i][j]想要成为回文串要新增的字符个数
    vector<vector<int>> dp(length, vector<int>(length, 0));

    for(int j = 1; j < length; j++)
    {
      // 先开始遍历一个维度，判断前后两个字符是不是一样 是的话不需要加 不是需要加一个就成为回文
      dp[j-1][j] = str[j - 1] == str[j] ? 0 : 1;
      for(int i = j - 2; i > -1; i--)
      {
        // 再遍历一个维度
        if(str[i] == str[j])
        {
          // 如果首尾一样，问题退化到上一层的结果
          dp[i][j] == dp[i+1][j-1];
        }
        else{
          // 如果不相等，则退化到上一层的结果 + 1，就是要么放头，要么放尾
          dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
        }
      }
    }

    res = dp[0][length -1];

    return res;
  }

  string getPalindrome(const string str)
  {
    string res = "";
    int length = str.size();
    if(length == 0 || length == 1)
    {
      return res;
    }

    // 声明一个二维数组，dp[i][j]代表的是字符串s[i][j]想要成为回文串要新增的字符个数
    vector<vector<int>> dp(length, vector<int>(length, 0));

    for(int j = 1; j < length; j++)
    {
      // 先开始遍历一个维度，判断前后两个字符是不是一样 是的话不需要加 不是需要加一个就成为回文
      dp[j-1][j] = str[j - 1] == str[j] ? 0 : 1;
      for(int i = j - 2; i > -1; i--)
      {
        // 再遍历一个维度
        if(str[i] == str[j])
        {
          // 如果首尾一样，问题退化到上一层的结果
          dp[i][j] == dp[i+1][j-1];
        }
        else{
          // 如果不相等，则退化到上一层的结果 + 1，就是要么放头，要么放尾
          dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
        }
      }
    }

    int addNumber = dp[0][length -1];
    int total = addNumber + length;
    string tmp(total,'x');
    int s_lhs = 0;
    int s_rhs = length - 1;
    int tmp_lhs = 0;
    int tmp_rhs = total - 1;
    while (s_lhs <= s_rhs) {
      if (str[s_lhs] == str[s_rhs]) {
        tmp[tmp_lhs++] = str[s_lhs++];
        tmp[tmp_rhs--] = str[s_rhs--];
      }
      else if (dp[s_lhs][s_rhs] == dp[s_lhs][s_rhs -1] + 1) {
        tmp[tmp_lhs++] = str[s_rhs];
        tmp[tmp_rhs--] = str[s_rhs--];
      }
      else {
        tmp[tmp_rhs--] = str[s_lhs];
        tmp[tmp_lhs++] = str[s_lhs++];
      }
    }
    res = tmp;
    return res;
  }

};


int main() {
  Solution solution;
  cout << solution.getPalindrome("acbc") << endl;
  return 0;
}
