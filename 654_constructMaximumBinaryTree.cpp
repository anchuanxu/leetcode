//
// Created by 安传旭 on 2021/3/17.
//
/*给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
 * 二叉树的根是数组 nums 中的最大元素。
 * 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
 * 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
 * 返回有给定数组 nums 构建的 最大二叉树 。
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size());
    }
    TreeNode* construct(vector<int>& nums, int l, int r)
    {
        if (l == r)
            return nullptr;
        int max_i = max(nums, l, r);
        TreeNode* root = new TreeNode(nums[max_i]);
        root->left = construct(nums, l, max_i);
        root->right = construct(nums, max_i + 1, r);
        return root;
    }
    int max(vector<int>& nums, int l, int r)
    {
        int max_i = l;
        for (int i = l; i < r; ++i) {
            if (nums[i] > nums[max_i])
                max_i = i;
        }
        return max_i;
    }
};

class Sup {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que; //声明一个序列，存储二叉树的节点

        if (root != nullptr)
        {
            que.push(root); //根节点非空，则将节点加入队列
        }
        vector<vector<int>> result; //声明一个动态数组存好几层。里面还是一个动态数组，存放每一层的节点
        while (!que.empty())
        {
            int size = que.size(); //固定大小size，因为que.size()是不断变化的
            vector<int> vec;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = que.front();
                que.pop();//队头出一个，后面队尾进两个
                vec.push_back(node->val); //用数组存好队头出队的值
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right); //队尾进两个（如果不空）
            }
            result.push_back(vec); //存储好 本层的节点
        }
        return result;
    }
};

int main()
{
    Solution solution;
    Sup      sup;
    vector<int> nums;
    int x;
    int n;
    cout << "Please enter numSize: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    TreeNode* tree;
    tree = solution.constructMaximumBinaryTree(nums);
    vector<vector<int>> result;
    result = sup.levelOrder(tree);
    cout << "[" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j != result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1)
            cout << "," ;
        cout<< endl;
    }
    cout << "]" << endl;
    return 0;
}