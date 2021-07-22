//
// Created by 传旭 on 2021/7/21.
//
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> res;
        int n = s.size();

        if (n <= 0 || words.empty())
            return res;

        int wordSize = words[0].size();
        int numWords = words.size();

        unordered_map<string, int> targetMap;

        for (string& word : words) {
            ++targetMap[word];
        }

        for (int i = 0; i < wordSize; ++i) {
            int left = i;
            int right = i;
            int cnt = 0;
            unordered_map<string, int> currMap;

            while (right + wordSize <= n)
            {
                string currWord = s.substr(right, wordSize);
                right += wordSize;

                if (targetMap.find(currWord) != targetMap.end())
                {
                    ++currMap[currWord];
                    ++cnt;
                    while (currMap[currWord] > targetMap[currWord])
                    {
                        string ts = s.substr(left, wordSize);
                        left += wordSize;
                        cnt--;
                        --currMap[ts];
                    }
                    if (cnt == numWords)
                    {
                        res.push_back(left);
                    }
                }
                else{
                    left = right;
                    cnt = 0;
                    currMap.clear();
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> result;
    vector<string> words = {"foo", "bar"};
    result = solution.findSubstring("barfoothefoobarman",words);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ,";
    }
    return 0;
}