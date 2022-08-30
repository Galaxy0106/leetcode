#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void debug(vector<vector<char>>& board){
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    // 往 x，y坐标的格子中填充 k 是否合法
    bool isSatisfied(vector<vector<char>>& board, int x, int y, char k){
        bool res = true;
        // 同一列
        for(int i = 0;i < board.size();i++){
            if(board[i][y] == k){
                res = false;
                break;
            }
        }
        // 同一行
        for(int j = 0;j < board[0].size();j++){
            if(board[x][j] == k){
                res = false;
                break;
            }
        }

        // 同一 3x3 宫
        int posx = x/3, posy = y/3;
        for(int i = posx*3;i < posx*3 + 3;i++){
            for(int j = posy*3;j < posy*3 + 3;j++){
                if(board[i][j] == k){
                    res = false;
                    break;
                }
            }
        }
        return res;
    }

    void findPos(vector<vector<char>>& board, int& x, int& y){
        x = -1, y = -1;
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                if(board[i][j] == '.'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        return;
    }

    bool helper(vector<vector<char>>& board){
        // debug(board);
        int x, y;
        findPos(board, x, y);
        if(x == -1 && y == -1)
            return true;
        bool flag = false;
        for(int k = 1;k <= 9;k++){
            char c = '0' + k;
            if(isSatisfied(board, x, y, c)){
                board[x][y] = c;
                flag = helper(board);
                if(flag)
                    return true;
                board[x][y] = '.';
            }
        }
        return false;
    }


    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    sol.solveSudoku(board);

    for(int i = 0;i < board.size();i++){
        for(int j = 0;j < board[0].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}