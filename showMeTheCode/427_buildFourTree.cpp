 //
// Created by 安传旭 on 2021/3/25.
//

/* 建立四叉树 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
 bool val;
 bool isLeaf;
 Node* topLeft;
 Node* topRight;
 Node* bottomLeft;
 Node* bottomRight;

 Node() {
     val = false;
     isLeaf = false;
     topLeft = NULL;
     topRight = NULL;
     bottomLeft = NULL;
     bottomRight = NULL;
 }

 Node(bool _val, bool _isLeaf) {
     val = _val;
     isLeaf = _isLeaf;
     topLeft = NULL;
     topRight = NULL;
     bottomLeft = NULL;
     bottomRight = NULL;
 }

 Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
     val = _val;
     isLeaf = _isLeaf;
     topLeft = _topLeft;
     topRight = _topRight;
     bottomLeft = _bottomLeft;
     bottomRight = _bottomRight;
 }
};

class Solution {
public:

    bool check(vector<vector<int>>& grid, int row1, int row2, int col1, int col2)
    {
        int unique = grid[row1][col1];

        for (int i = row1; i < row2; i++)
        {
            for (int j = col1; j < col2; ++j) {
                if (unique != grid[i][j]) return false;
            }
        }
        return true;
    } //遍历函数，遍历一遍该区域，检查元素是否全部相同，全部相同返回true

    Node *helper(vector<vector<int>>& grid, int row1, int row2, int col1, int col2)
    {
        if (check(grid, row1, row2, col1, col2))
        {
            return new Node(grid[row1][col1], true);
        }//该区域元素全部一样，则该区域为叶子节点，返回node，并且isleaf是true

        int step = (row2 - row1) / 2; //划分区间
        Node* ret = new Node(grid[row1][col1], false); //该区域元素不全部一致，不是叶子节点，isleaf返回false；
        //从这个区域内开始递归
        ret->topLeft = helper (grid, row1, row1 + step, col1, col1 + step);
        ret->topRight = helper(grid, row1, row1 + step,  col1 + step, col2);
        ret->bottomLeft  = helper(grid, row1 + step, row2, col1, col1 + step);
        ret->bottomRight = helper(grid, row1 + step, row2, col1 + step, col2);
        return ret;
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, grid.size(), 0, grid[0].size());
    }
};

int main()
{
    vector<vector<int>> grid(0,vector<int>(0)); //初始化grid，行为0，列为0

    
    return 0;
}
