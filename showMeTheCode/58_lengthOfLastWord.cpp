#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
      int end = s.size() - 1;
      while(end >= 0 && s[end] == ' ')
      {
        end --;
      }
      if(end < 0) return 0;
      int start = end;
      while(s[start] != ' ' && start >= 0)
      {
        start --;
        if(start < 0)
        {
          break;
        }
      }

      return end - start;
    }
};

int main() {
  Solution solution;
  cout << solution.lengthOfLastWord("a");
  return 0;
}
