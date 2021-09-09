#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(!n)
        {
            return {};
        }
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end)
    {
        if(start > end)
        {
            return {nullptr};
        } //递归出口
        vector<TreeNode*> allTrees; //枚举可行的根节点

        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1); //递归求左子树

            vector<TreeNode*> rightTrees = generateTrees(i + 1, end); //递归求右子树

            //从左右各选出一颗子树，拼接到根节点上

            for(auto& left : leftTrees){
                for(auto& right : rightTrees)
                {
                    TreeNode* currentTree = new TreeNode(i);
                    currentTree->left = left;
                    currentTree->right = right;
                    allTrees.emplace_back(currentTree);
                }
            }
        }
        return allTrees;
    }
};