#include <iostream>
#include <vector>
#include <cassert>
using namespace std;



class Solution {
private:
    int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int m,n;
    bool inArea(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    vector<vector<bool>> visited;

    bool searchWord(const vector<vector<char>> &board,const string& word, int index, int startx, int starty){

        if(index == word.size() -1)
            return board[startx][starty] == word[index];

        if(board[startx][starty] ==  word[index]){

            visited[startx][starty] = true;
            //向四个方向寻找
            for(int i = 0; i < 4; i++){
                int newx = startx + d[i][0];
                int newy = starty + d[i][1];
                if(inArea(newx,newy) && !visited[newx][newy]){
                    if(searchWord(board,word,index + 1,newx,newy))
                        return true;
                }
            }

            visited[startx][starty] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        assert(m > 0);
        n = board[0].size();

        visited = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j <board[i].size(); j++){
                if(searchWord(board,word,0,i,j))
                    return true;

            }
        }
        return false;

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}