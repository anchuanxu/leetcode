//
// Created by 安传旭 on 2021/3/11.
//
/*给定一个二叉树，返回所有从根节点到叶子节点的路径。*/
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

class Solution{
public:
    void construct_paths(TreeNode* root, string path, vector<string>& paths)
    {
        if (root != nullptr) {
            path += to_string(root->val);
            if (root->left == nullptr && root->right == nullptr) {
                //当前节点即为叶子节点
                paths.push_back(path);
            } else {
                path += "->";
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        construct_paths(root, " ", paths);
        return  paths;
    }
};

class  Sup {
public:
    TreeNode* initBTree(int elements[], int size)
    {
        if(size < 1)
        {
            return NULL;
        }
        //动态申请size大小的指针数组
        TreeNode **nodes = new TreeNode*[size];
        //将int数据转换为TreeNode节点
        for (int i = 0; i < size; i++)
        {
            if (elements[i] == 0)
            {
                nodes[i] = NULL;
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
    Sup      sup;
    int numSize;
    cout << "Please enter numSize： " << endl;
    cin >> numSize;
    int nums[numSize] ;
    cout << "Please enter numbers: " << endl;
    for (int i = 0; i < numSize; ++i) {
        cin >> nums[i];
    }
    TreeNode *BTree;
    BTree = sup.initBTree(nums, numSize);
    vector<string> paths;
    paths = solution.binaryTreePaths(BTree);
    for (int i = 0; i < paths.size(); ++i) {
        cout << paths[i];
    }
    return 0;
}