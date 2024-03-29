#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // 定义状态数组dp
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp = vector<vector<int>> (m, vector<int>(n));

        // 初始化 base case
        dp[0][0] = grid[0][0];
        for(int j = 1;j < n;j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for(int i = 1;i < m;i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }

        // 状态转移方程
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    Solution sol;
    vector<vector<int>> input = {{1,3,1}, {1,5,1},{4,2,1}};
    cout << sol.minPathSum(input);
    return 0;
}