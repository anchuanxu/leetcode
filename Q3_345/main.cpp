#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseVowels( string s) {
        //if(s.size() <= 0) return 0;
        //if(s.size() == 1) return 0;
        //在字符串的时候不能判定，加上这两句会有报错：Char 9: runtime error: pointer index
        // expression with base 0x000000000000 overflowed to 0xffffffffffffffff (basic_string.h)

        int p = 0;
        int q = s.size()-1;

        while(p < q){
            while(!Isyuanyin(s[p]) && p < q) p++;
            while(!Isyuanyin(s[q]) && p < q) q--;
            swap(s[p++],s[q--]);
        }
        return s;
    }

public:
    bool Isyuanyin(char s){
        if(s == 'a' || s == 'e' ||s == 'i' ||s == 'o' ||s == 'u' ||s == 'A'||s == 'E'||s == 'I'||s == 'O'||s == 'U')
            return true;
        else
            return false;
    }
};

int main() {
    string a = "leetcode";

    cout<<Solution().reverseVowels(a);

    cout<<endl;
    return 0;
}