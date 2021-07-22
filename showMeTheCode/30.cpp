//
// Created by 传旭 on 2021/7/21.
//




class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size();

        // 边缘情况
        if (n <= 0 || words.empty())
        {
            return res;
        }

        // 单词的大小
        int wordSize = words[0].size();
        // 单词数量
        int numWords = words.size();

        // words的单词到次数的映射
        unordered_map<string, int> targetMap;
        for (string& word : words)
        {
            ++targetMap[word];
        }


        // 起点以 one_word来偏移，这样子就可以覆盖所有的情况
        for (int i = 0; i < wordSize; ++i)
        {
            // 记录当前统计的窗口的left和 right， 以及已匹配的单词个数 cnt
            int left = i;
            int right = i;
            int cnt = 0;

            // 当前窗口的映射表
            unordered_map<string, int> currMap;

            // 窗口移动
            while (right + wordSize <= n)
            {
                // 提取以right为边界的 wordSize为大小的单词
                string currWord = s.substr(right, wordSize);
                right += wordSize;

                if (targetMap.find(currWord) != targetMap.end())
                {
                    // 存在该单词
                    ++currMap[currWord];
                    ++cnt;
                    // 需要检查数量是否超过，超过则要左移left来缩小窗口
                    while (currMap[currWord] > targetMap[currWord])
                    {
                        string ts = s.substr(left, wordSize);
                        left += wordSize;
                        --cnt;
                        --currMap[ts];
                    }
                    if (cnt == numWords)
                    {
                        res.push_back(left);
                    }
                }
                else
                {
                    // 不存在单词
                    left = right;
                    cnt = 0;
                    currMap.clear();
                }
            }
        }

        return res;
    }
};
