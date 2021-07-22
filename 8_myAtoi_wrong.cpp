//
// Created by 传旭 on 2021/7/5.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Automaton{
    string state = "start";
    unordered_map<string, vector<string>> table = {
            {"start",{"start","signed","in_number","end"}},
            {"signed",{"end","end","in_number","end"}},
            {"in_number",{"end","end","in_number","end"}},
            {"end",{"end","end","end","end"}},
    };
    int get_col(char c)
    {
        if (isspace(c)) return 0; //是不是空格判断
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2; //是不是十进制数字判断函数
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;

    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MAX);
        }
        else if (state == "signed")
        {
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution{
public:
    int myAtoi(string str)
    {
        Automaton automaton;
        for (char c : str) {
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }
};

int main()
{
    Solution solution;
    string string1;
    cout << "Please enter a string = ";
    cin >> string1;
    cout << "A to i = " << solution.myAtoi(string1) << endl;
    return 0;
}