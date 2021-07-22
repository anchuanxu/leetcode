//
// Created by 传旭 on 2021/7/8.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size()))); //声明行数组，每一个元素存储对应行的字符串
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] = rows[curRow] + c; //改行增加一个字符

            //行为判断，是否到顶或者到底
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown; //访问方向调转
            if (goingDown)
            {
                curRow ++;
            }else{
                curRow --;
            }
            //简洁写法
            //goingDown ? curRow++ : curRow--;
        }

        string res;
        for (string row : rows)
        {
            res = res + row;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string string1;
    int n;
    cout << "Please enter a string : " << endl;
    cin >> string1;
    cout << "Please enter how many rows you want: " << endl;
    cin >> n;
    cout << "The convert string is : " << solution.convert(string1, n) << endl;
    return 0;
}