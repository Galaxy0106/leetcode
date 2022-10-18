#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 判断行
        for(int i = 0;i < board.size();i++){
            unordered_set<char> st;
            for(int j = 0;j < board[i].size();j++){
                char c = board[i][j];
                if(c != '.'){
                    if(st.count(c))
                        return false;
                    else
                        st.insert(c);
                }
            }
        }
        // 判断列
        for(int j = 0;j < board[0].size();j++){
            unordered_set<char> st;
            for(int i = 0;i < board.size();i++){
                char c = board[i][j];
                if(c != '.'){
                    if(st.count(c))
                        return false;
                    else
                        st.insert(c);
                }
            }
        }
        // 判断九宫格
        for(int k = 0;k < 9;k++){
            int base_x = k/3 * 3;
            int base_y = k%3 * 3;
            unordered_set<char> st;
            for(int i = base_x;i < base_x+3;i++){
                for(int j = base_y;j < base_y+3;j++){
                    char c = board[i][j];
                    if(c != '.'){
                        if(st.count(c))
                            return false;
                        else
                            st.insert(c);
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    

    return 0;
}