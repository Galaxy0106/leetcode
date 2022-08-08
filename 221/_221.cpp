#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int min3(int a, int b, int c){
        return min(min(a, b), c);
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int res_len = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        // 定义dp数组，dp[i][j]表示以下标 i,j 为右下角的正方形的最大边长
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 初始化base case
        for(int j = 0;j < n;j++){
            if(matrix[0][j] == '0')
                dp[0][j] = 0;
            else{
                dp[0][j] = 1;
                res_len = max(res_len, dp[0][j]);
            }
        }

        for(int i = 0;i < m;i++){
            if(matrix[i][0] == '0')
                dp[i][0] = 0;
            else{
                dp[i][0] = 1;
                res_len = max(res_len, dp[i][0]);
            }
        }
        // 状态转换
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                    res_len = max(res_len, dp[i][j]);
                }
            }
        }
        return res_len*res_len;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << sol.maximalSquare(matrix);
    return 0;
}