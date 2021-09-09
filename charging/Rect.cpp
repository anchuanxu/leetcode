// 在线面试平台。将链接分享给你的朋友以加入相同的房间。
//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像逆时针旋转 90 度。
//给定 matrix = 
//[
//  [1,2,3],
//  [4,5,6],
//  [7,8,9]
//],

//原地旋转输入矩阵，使其变为:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
#include <iostream>
#include <vector>

using namespace std;


//使用o(1)的空间完成题目
void rotateMatrix(vector<vector<int> > mat){
  
  int v = mat[0].size();
  int temp = 0;
  
  //矩阵的转置
  for(int i = 0; i < v; i++)
  {
    for(int j = i; j < v; j++)
    {
    	temp = mat[i][j];
      mat[i][j] = mat[j][i];
      mat[j][i] = temp;
    }
  }
  
  //矩阵的对称
  for(int i = 0; i < v; i++)
    for(int j = v - 1; j >= 0; j--)
    {
      temp = mat[i][j];
      mat[i][v - j - 1] = mat[i][j];
      mat[i][j] = temp;
    } 
  return;
}

//使用o(n)的空间完成题目
void rotateMatrix(vector<vector<int> > mat){
    vector<vector<int> > res;
    res = mat;
    int v = mat[0].size();
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            res[i][j] = mat[v - 1 - j][i];
        }
    }
    mat = res;
    return;
}
