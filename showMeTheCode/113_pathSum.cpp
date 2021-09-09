#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > res; 
    vector<int> path;

    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
       dfs(root, targetSum);
       return res;
    }
    void dfs(TreeNode* root, int targetSum)
    {
        if(root == nullptr) return;
        path.push_back(root->val);
        targetSum -= root->val; 
        if(root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            res.push_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
        return;
    }
};