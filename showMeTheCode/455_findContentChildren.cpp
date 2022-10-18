#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size();
        int n = s.size();
        int res = 0;

        for(int i = 0, j = 0; i < m && j < n; i++, j++)
        {
            while(j < n && s[j] < g[i])
            {
                j++;
            }
            if(j < n)
            {
                res++;
            }
        }

        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution solution;
    vector<int> g = {1,2,3};
    vector<int> s = {1,2};
    cout << solution.findContentChildren(g,s) << endl;
    return 0;
}
