//
// Created by 传旭 on 2021/7/1.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int dig;
        while (x != 0)
        {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10)
            {
                return 0;
            }
            dig = x % 10;
            x /= 10;
            rev = rev * 10 + dig;
        }
        return rev;
    }
};

int main()
{
    Solution solution;
    int x;
    cin >> x;
    cout << " reverse x = " << solution.reverse(x) << endl;
    return 0;
}
