//
// Created by 传旭 on 2021/7/9.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (x % 10 == 0) return false;

        //开始旋转后半部分数字，临界条件是小于剩余部分数字
        int temp = 0;

        while (temp < x)
        {
            temp = x % 10 + temp * 10;
            x = x / 10;
        }

        return temp == x || temp / 10 == x ? true : false; // temp是奇数的时候，通过temp / 10 去除中位数。
    }
};

int main()
{
    Solution solution;
    int x;
    cin >> x;
    cout << solution.isPalindrome(x) << endl;
    return 0;
}