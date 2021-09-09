#include <iostream>
#include <unordered_map>
#include <vector>

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
    private:
    unordered_map<int, int> index;
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        //构建哈希表映射，帮助我们快速定位根节点
        for(int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n-1, 0, n-1);
    }
    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int preorder_left, int preorder_right
    , int inorder_left, int inorder_right)
    {
        if(preorder_left > preorder_right) return nullptr;

        //前序遍历第一个节点就是根节点
        int preorder_root = preorder_left;
        //在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];
        //先把根节点建立起来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        //得到左子树中节点的数目
        int size_left_subtree = inorder_root - inorder_left;
        //递归的构建左子树
        root->left = myBuildTree(preorder, inorder,preorder_left + 1, preorder_left + size_left_subtree, 
        inorder_left, inorder_root - 1);
        //递归的构建右子树
        root->right = myBuildTree(preorder, inorder,preorder_left + size_left_subtree + 1, preorder_right,
        inorder_root + 1, inorder_right);

        return root;
    }
};

int main()
{
    Solution solution;
    int arr1[5] = {3,9,20,15,7};
    int arr2[5] = {9,3,15,20,7};
    vector<int> nums1(arr1, arr1 + 5);
    vector<int> nums2(arr2, arr2 + 5);
    
}