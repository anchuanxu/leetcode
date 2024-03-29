#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<bool> col;
    vector<bool> dia1;
    vector<bool> dia2;

    void putQueen(int n,int index,vector<int> &row){
        if (index == n){
            res.push_back(generateBoard(n,row));
            return;
        }

        for(int i = 0; i < n; i ++){
            if(!col[i] && !dia1[index + i] && !dia2[index-i+n-1]){
                row.push_back(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index-i+n-1] = true;
                putQueen(n, index + 1, row);
                col[i] = false;
                dia1[index + i] = false;
                dia2[index-i+n-1] = false;
                row.pop_back();

            }
        }
        return;
    }

    vector<string> generateBoard(int n,vector<int> &row){
        assert(row.size() == n);
        vector<string> board(n,string(n,'.'));
        for(int i = 0; i < n; i++){
            board[i][row[i]] = 'Q';
        }
        return board;
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        res.clear();

        col = vector<bool>(n,false);
        dia1 = vector<bool>(2*n-1,false);
        dia2 = vector<bool>(2*n-1,false);

        vector<int> row;
        putQueen(n,0,row);

        return res;

    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<string>> res = Solution().solveNQueens(n);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < n; j++){
            cout<<res[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}