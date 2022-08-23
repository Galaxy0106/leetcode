#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<bool>>& is_visited, string word, int i, int j, int k) {
        if(board[i][j] != word[k])
            return false;
        if(k == word.size() - 1)
            return true;

        is_visited[i][j] = true;
        bool res = false;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto& dir : dirs){
            int ix = i + dir.first; // 上下
            int iy = j + dir.second;
            if(ix >= 0 && ix < board.size() && iy >=0 && iy < board[0].size()){
                if(is_visited[ix][iy] == false){
                    bool flag = check(board, is_visited, word, ix, iy, k+1);
                    if(flag){
                        res = true;
                        break;
                    }
                }
            }
        }
        is_visited[i][j] = false;
        return res;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        // 是否访问过的记录
        vector<vector<bool>> is_visited(m, vector<bool>(n, false));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                bool flag = check(board, is_visited, word, i, j, 0);
                if(flag)
                    return true;
            }
        }
        return false;
    }
};

int main(){

    return 0;
}