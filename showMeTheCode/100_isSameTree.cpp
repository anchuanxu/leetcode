//
// Created by 安传旭 on 2021/3/16.
//
/*给你两棵二叉树的根节点p和q，编写一个函数来验证这两棵树是否相同。如果两棵树在结构上是相同的，并且节点具有相同的值，则认为这两棵树是相同的*/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return  p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    TreeNode *Tree1, *Tree2;
    string string1;
    Tree1 = sup.initBTree(nums, numSize);
    Tree2 = sup.initBTree(nums, numSize);


    if (solution.isSameTree(Tree1, Tree2) == true)
    {
        string1 = "Yes";
    }
    else{
        string1 = "No";
    }
    cout << "This tree is same tree ? " << string1 << endl;
    return 0;
}