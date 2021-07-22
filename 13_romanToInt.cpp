//
// Created by chuanxu on 2021/6/28.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution{
private:
    unordered_map<char, int> symboValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
    };
public:
    int romanToint(string s)
    {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = symboValues[s[i]];
            if (i < n - 1 && value < symboValues[s[i + 1]])
            {
                ans = ans - value;
            }
            else{
                ans = ans + value;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string string1;
    cout << "Please enter a string = ";
    cin >> string1;
    int result;
    result = solution.romanToint(string1);
    cout << "Roman to Int = " << result << endl;
    return 0;
}
