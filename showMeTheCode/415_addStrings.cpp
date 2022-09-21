#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
      int i = num1.length() - 1;
      int j = num2.length() - 1;
      int add = 0;
      string res;

      while(i >= 0 || j >= 0 || add != 0)
      {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        add = result / 10;
        res.push_back(result % 10 + '0');
        i--;
        j--;
      }
      reverse(res.begin(), res.end());

      return res;
    }
};

int main() {
  Solution solution;
  cout << solution.addStrings("12", "123");
  return 0;
}
