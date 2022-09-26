#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getLargeStr(string string1)
    {
        string res;
        vector<string> res_arr;
        for(int i = 0; i < string1.size(); i++)
        {
            int index = i;
            string tem_string;
            while(std::isdigit(string1[index]) && index < string1.size())
            {
                tem_string.push_back(string1[index]);
                index ++;
            }
            i = index;
            res_arr.push_back(tem_string);
        }

        int max = 0;
        for(int i = 0; i < res_arr.size(); i++)
        {
            cout << res_arr[i] << endl;
            if(pureLength(res_arr[i]) >= max)
            {
                max = pureLength(res_arr[i]);
                res = res_arr[i];
            }
        }

        return res;
    }

    int pureLength(string str)
    {
        unordered_map<int , char> str_map;
        if(str.empty()) return 0;
        for(int i = 0; i < str.size(); i++)
        {
            str_map.emplace(str[i] - '0', str[i]);
        }

        return str_map.size();
    }

};


int main() {
    Solution solution;

    cout << solution.getLargeStr("a12b123bb12345bbb1235666666");
    return 0;
}