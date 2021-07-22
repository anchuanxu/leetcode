#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int p ;
        int q ;
        //定义双指针，分别从两头扫描

        int max = 0;//初始化最大值为0;

        if(q == 1){
            max = min(height[p],height[q]);
        }
        else {
            /*
            for (p = 0; p < height.size() -1 ; p++) {
                for (q = height.size() - 1 ; q > p; q--) {
                    if ((minInt(height[p], height[q]) * (q - p)) > max)
                        max = (minInt(height[p], height[q]) * (q - p));
                }
            }*/

            for(p = 0,q = height.size() -1; p < q;){
                if(height[p] > height[q]){
                    max = maxInt(max ,height[q] * (q - p));
                    q--;
                }
                else{
                    max = maxInt(max,height[p] * (q - p));
                    p++;
                }
            }
        }
        return max;

    }
private:
    int maxInt(int a,int b){
        if (a >= b)
            return a;
        else
            return b;
    }
};

int main() {
    vector<int> vec ={1,8,6,2,5,4,8,3,7};
    cout<<Solution().maxArea(vec)<<endl;
    return 0;
}