#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> ds;

        int n = path.size();
        int i = 0;
        while (i < n)
        {
            if(i < n && path[i] == '/')
            {
                i++;
            } else{
                string part;
                while(i < n && path[i] != '/')
                {
                    part += path[i++];
                }
                if(part == ".." && !ds.empty()) ds.pop_back();
                else if(part != ".." && part != ".") ds.push_back(part);
            }
        }
        string res = "/";
        while (!ds.empty())
        {
            res += ds.front() + "/";
            ds.pop_front();
        }
        if(res.size() > 1)
        {
            res.pop_back();
        }

        return res;

    }
};

int main() {
    Solution solution;
    cout << solution.simplifyPath("//home//chuanxu/...//") << endl;

    return 0;
}
