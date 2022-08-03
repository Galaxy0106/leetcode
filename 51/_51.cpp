#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    bool is_valid(vector<string>& board, int m, int n){
        int len = board.size();
        // 同一行
        for(int j = 0;j < len;j++){
            if(j != n && board[m][j] == 'Q'){
                return false;
            }
        }
        // 同一列
        for(int i = 0;i < len;i++){
            if(i != m && board[i][n] == 'Q'){
                return false;
            }
        }
        // 同一斜线
        for(int k = 1;k <= m && k <= n;k++){
            if(board[m-k][n-k] == 'Q')
                return false;
        }
        for(int k = 1;k < len - m && k < len - n;k++){
            if(board[m+k][n+k] == 'Q')
                return false;
        }

        for(int k = 1;k < len - m && k <= n;k++){
            if(board[m+k][n-k] == 'Q')
                return false;
        }
        for(int k = 1;k <= m && k < len-n;k++){
            if(board[m-k][n+k] == 'Q')
                return false;
        }
        return true;
    }

    void backtrack(vector<string>& board, int row){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        for(int col = 0;col < board.size();col++){
            if(is_valid(board, row, col)){
                board[row][col] = 'Q';
                backtrack(board, row+1);
                board[row][col] = '.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<string>> res = sol.solveNQueens(4);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}