#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st; //声明一个栈
        vector<bool> mark(s.length()); //声明一个标记数组

        for(int i = 0; i < mark.size(); i++)
            mark[i] = 0; //标记所以的字符为0 初始化操作
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i); //将index压入栈中
            }
            else{
                if(st.empty()) mark[i] = 1; //现在是右括号，但是栈中已空，无左括号可以匹配，标记i为1
                else{
                    st.pop(); //弹出一个左括号，进行匹配
                }
            }
        }
        //此时遍历完，栈中还有元素，那通通标记，无括号可以再匹配
        while(!st.empty())
        {
            mark[st.top()] = 1;//记住 栈中存的是index；
            st.pop();
        }
        //栈操作结束了，现在原来的字符串被标记为 1000001001 类似的数字串，进行寻找最长0串
        int len = 0, res = 0; 
        for(int i = 0; i < s.length(); i++)
        {
            if(mark[i])
            {
                len = 0;
                continue;
            }
            else{
                len++;
                res = max(len, res);
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    string string1 = "(((())))()()(";
    cout << "The Longest Valid Parentheses = " << solution.longestValidParentheses(string1) << endl;
    return 0;
}