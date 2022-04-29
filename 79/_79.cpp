#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is_over(vector<vector<char>>& board){
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                if(board[i][j] != '#')
                    return false;
            }
        }
        return true;
    }

    bool bfs(vector<vector<char>>& board, int pos_x, int pos_y, string temp, string word){    
        // Judge if over
        if(is_over(board) && temp != word){
            return false;
        }

        if(temp == word){
            return true;
        }

        // up
        




    }

    bool exist(vector<vector<char>>& board, string word) {
        // Initialize a record
        for(int i = 0;i < board.size();i++){
            vector<bool> temp;
            for(int j = 0;j < board[i].size();j++){
                temp.push_back(false);
            }
            record.push_back(temp);
        }
        // Initialize an empty string
        string temp;
        // BFS
        bool res;
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[i].size();j++){
                res = bfs(board, record, i, j, temp, word);

            }
        }



    }
};


int main(){



    return 0;
}