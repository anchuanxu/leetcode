#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 0) return;
        if(s.size() == 1) return;

        int p = 0;
        int q = s.size()-1;

        while(p < q){
            swap(s[p++],s[q--]);
        }
    }
};

int main() {
    char a[] = {'H','E','L','L','O'};
    vector<char> vec(a,a + sizeof(a)/ sizeof(char));
    Solution().reverseString(vec);
    for(int i = 0; i < 5; i++){
        cout<<vec[i];
    }
    cout<<endl;
    return 0;
}