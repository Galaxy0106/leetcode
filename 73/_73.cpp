#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false, col0 = false;
        // 列
        for(int i = 0;i < matrix.size();i++){
            if(matrix[i][0] == 0){
                col0 = true;
                break;
            }
        }
        // 行
        for(int j = 0;j < matrix[0].size();j++){
            if(matrix[0][j] == 0){
                row0 = true;
                break;
            }
        }
        // 在第一行和第一列存放标志位
        for(int i = 1;i < matrix.size();i++){
            for(int j = 1;j < matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // 置0
        for(int i = 1;i < matrix.size();i++){
            for(int j = 1;j < matrix[i].size();j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(row0){
            for(int j = 0;j < matrix[0].size();j++){
                matrix[0][j] = 0;
            }
        }
        if(col0){
            for(int i = 0;i < matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
        return;
    }
};

int main(){

    return 0;
}