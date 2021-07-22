//
// Created by 传旭 on 2021/7/21.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend > INT_MIN ? -dividend : INT_MAX;

        long a = dividend;
        long b = divisor;

        int sign = 1;
        if ((a > 0 && b < 0) ||(a < 0 && b > 0))
            sign = -1;

        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;

        long res = div(a, b);
        if (sign> 0) return res > INT_MAX ? INT_MAX : res;
        else
            return  -res;
    }

    int div(long a, long b)
    {
        if (a < b) return 0;

        long temp_b = b;
        long count = 1;

        while (temp_b + temp_b <= a)
        {
            temp_b = temp_b + temp_b;
            count = count + count;
        }
        return count + div(a - temp_b, b);
    }
};

int main()
{
    Solution solution;
    cout << solution.divide(-2147483648,2) << endl;
    return 0;
}