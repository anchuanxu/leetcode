#include <iostream>

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int leftMaxDepth = maxDepth(root->left);
        int rightMaxDepth = maxDepth(root->right);

        return max(leftMaxDepth,rightMaxDepth);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}