#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int posX, int posY, vector<vector<char>>& board, vector<vector<bool>>& isVis, string word, int posStr){
        cout << posStr << board[posX][posY] << " ";
        if(board[posX][posY] != word[posStr]){
            isVis[posX][posY] = false;
            return false;
        }
        isVis[posX][posY] = true;

        // 向上
        if(posX > 0 && !isVis[posX-1][posY]){
            if(dfs(posX-1, posY, board, isVis, word, posStr + 1))
                return true;
        }
        // 向下
        if(posX < isVis.size() - 1 && !isVis[posX+1][posY]){
            if(dfs(posX+1, posY, board, isVis, word, posStr + 1))
                return true;
        }
        // 向左
        if(posY > 0 && !isVis[posX][posY-1]){
            if(dfs(posX, posY-1, board, isVis, word, posStr + 1))
                return true;
        }
        // 向右
        if(posY < isVis[0].size() - 1 && !isVis[posX][posY+1]){
            if(dfs(posX, posY+1, board, isVis, word, posStr + 1))
                return true;
        }
        if(posStr == word.size() - 1)
            return true;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                int m = board.size();
                int n = board[i].size();
                vector<vector<bool>> isVis = vector<vector<bool>>(m, vector<bool>(n));
                res = dfs(i, j, board, isVis, word, 0);
                if(res)
                    return true;
            }
        }
        return res;
    }
};

using namespace std;

int main(){
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','E','S'}, {'A','D','E','E'}};
    Solution sol;
    cout << sol.exist(board, "ABCESEEEFS");
    return 0;
}