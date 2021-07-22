//
// Created by chuanxu on 2021/6/29.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const pair<int, string> valueSymbols[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
};

class Solution{
public:
    string intToRoman(int num) {
        string roman;
        for (const auto &[value, symbol] : valueSymbols)
        {
            while (num >= value)
            {
                num = num - value;
                roman = roman + symbol;
            }
            if (num == 0)
            {
                break;
            }
        }
        return roman;
    }
};

int main()
{
    Solution solution;
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    string res;
    res = solution.intToRoman(n);
    cout << "The num to roman is : " << res << endl;
    return 0;
}