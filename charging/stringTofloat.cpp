#include <iostream>

using namespace std;

class Solution{
    public:
    float stringTofloat(char *s)
    {
        int len = strlen(s);
        int i = 0;
        int j;
        char purestr[len];
        float res;

        for(i = 0; i < len; i++)
        {
            if(s[i] > '0' && s[i] <= '9')
            {
                break; //先找到浮点数的第一个index
            }
        }
        for(j = i; j < len; j++)
        {
            if((s[j] > '0' && s[j] <= '9' )|| s[j] == '.')
            {
                purestr[j - i] = s[j]; //保存下来浮点数字符串
            }
            else{
                break;
            }
        }

        sscanf(purestr, "%f", &res); //https://www.runoob.com/cprogramming/c-function-sscanf.html

        return res;
    }
};

int main()
{
    char string1[20] = "absc924.56bb";
    Solution solution;
    cout << solution.stringTofloat(string1) << endl;
    return 0;
}