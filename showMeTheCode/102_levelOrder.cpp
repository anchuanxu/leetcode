//
// Created by 安传旭 on 2021/3/17.
//
/*二叉树的层序遍历*/
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
    string string1;
    BTree = sup.initBTree(nums, numSize);

    vector<vector<int>> result;
    result = solution.levelOrder(BTree);
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