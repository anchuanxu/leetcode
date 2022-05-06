#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    int res = 0;
    vector<int> max_left(height.size(), 0);
    vector<int> max_right(height.size(), 0);

    for(int i = 1; i < height.size() - 1; i++)
    {
        max_left[i] = max(max_left[i-1], height[i-1]);
    }
    for(int i = height.size() - 2; i > 0; i--)
    {
        max_right[i] = max(max_right[i+1], height[i+1]);
    }
    for(int i = 1; i < height.size() - 1; i++)
        {
            int min_wall = min(max_left[i], max_right[i]);
            if(min_wall > height[i])
            {
                res += (min_wall - height[i]);
            }
        }
        return res;
    }
};