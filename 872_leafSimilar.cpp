//
// Created by 安传旭 on 2021/3/18.
//
/*请考虑一棵二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。请判断两棵树的叶值序列，如果相等，则返回true，如果不等，则返回false*/

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);
        return  leaves1 == leaves2; //动态数组可以直接进行比较
    }
    void dfs(TreeNode* node, vector<int>& leaves)
    {
        if (node == nullptr)
            return;
        if (node->left == nullptr && node->right == nullptr)
        {
            leaves.push_back(node->val);
        }
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
};

class  Sup {
public:
    TreeNode* initBTree(int elements[], int size)
    {
        if(size < 1)
        {
            return nullptr;
        }
        //动态申请size大小的指针数组
        TreeNode **nodes = new TreeNode*[size];
        //将int数据转换为TreeNode节点
        for (int i = 0; i < size; i++)
        {
            if (elements[i] == 0)
            {
                nodes[i] = nullptr;
            }
            else
            {
                nodes[i] = new TreeNode(elements[i]);
            }
        }
        //定义一个队列
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(nodes[0]);

        TreeNode *node;
        int index = 1;
        while (index < size)
        {
            //队列头出来一个，队列尾进两个,同时进行着二叉树的左右分支初始化
            node = nodeQueue.front();
            nodeQueue.pop();
            nodeQueue.push(nodes[index++]);
            node->left = nodeQueue.back();
            nodeQueue.push(nodes[index++]);
            node->right = nodeQueue.back();
        }
        return nodes[0]; //返回根节点
    }
};

int main()
{
    Solution solution;
    Sup sup;
    int numSize1, numSize2;
    cout << "Please enter numSize1： " << endl;
    cin >> numSize1;
    cout << "Please enter numSize2： " << endl;
    cin >> numSize2;
    int nums1[numSize1], nums2[numSize2];
    cout << "Please enter numbers to nums: " << endl;
    for (int i = 0; i < numSize1; ++i) {
        cin >> nums1[i];
    }
    cout << "Please enter numbers to nums2: " << endl;
    for (int i = 0; i < numSize2; ++i) {
        cin >> nums2[i];
    }
    TreeNode *Tree1, *Tree2;
    Tree1 = sup.initBTree(nums1, numSize1);
    Tree2 = sup.initBTree(nums1, numSize1);
    bool result;
    result = solution.leafSimilar(Tree1,Tree2);
    cout << "This two tree leafSimilarl is : " ;
    if (result)
    {
        cout << "yes" << endl;
    } else{
        cout << "no" << endl;
    }
    return 0;
}
