#include <iostream>
#include <cmath>
using namespace std;

class Solution{
    public:
    double distance(double x1, double x2, double y1, double y2)
    {  
        return sqrt((x1 -x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};

int main()
{
    Solution solution;
    double x1 = 0.00155988447597;
    double x2 =  -0.881372805124;
    double y1 = 0.00515412198795;
    double y2 = 0.033363511156;
    cout << solution.distance(x1,x2,y1,y2) << endl;
    return 0;
}