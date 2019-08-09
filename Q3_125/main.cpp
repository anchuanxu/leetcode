#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() == 0)
            return true;
        int l = l_next(s,0);
        int r = r_pre(s,s.size()-1);

        while(l <= r){
            if(tolower(s[l]) != tolower(s[r])) //tolower()函数，转换字母为小写，非字母元素不处理；
                return false;
            l = l_next(s,l+1);
            r = r_pre(s,r-1);
        }
        return true;
    }

private:
    int l_next(const string& s,int index){
        for(int i = index; i < s.size(); i++){
            if(isalnum(s[i])) //isalnum()函数，判断是不是字母
                return i;
        }
        return s.size();
    }

private:
    int r_pre(const string& s, int index){
        for(int i = index; i >= 0; i--){
            if(isalnum(s[i]))
                return i;
        }
        return -1;
    }
};

int main() {

    string string1 = {"A man, a plan, a canal: Panama"};

    Solution().isPalindrome(string1);

    return 0;
}