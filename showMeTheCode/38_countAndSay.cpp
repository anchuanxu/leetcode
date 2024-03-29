#include <iostream>

using namespace std;

class Solution{
    public:
    string countAndSay(int n)
    {
        string prev = "1";
    
        for(int i = 2; i <= n; i++)
        {
            string cur = "";
            int pos = 0;
            int start = 0;
            while(pos < prev.size())
            {
                while(pos < prev.size() && prev[pos] == prev[start])
                {
                    pos++;
                }
                cur += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = cur;
        }
    
        return prev;
    }
};