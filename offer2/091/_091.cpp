#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        // 定义 dp 数组
        // dp[i][j] 表示 第 i 个 房子 染成 j (r, g, b) 颜色 的最少成本
        vector<vector<int>> dp(n+1, vector<int>(3, 0));
        // 初始化 base case
        int dp0 = 0;
        int dp1 = 0;
        int dp2 = 0;
        for(int i = 1;i <= n;i++){
            int dp0_temp = dp0;
            int dp1_temp = dp1;
            int dp2_temp = dp2;
            dp0 = min(dp1_temp, dp2_temp) + costs[i-1][0];
            dp1 = min(dp0_temp, dp2_temp) + costs[i-1][1];
            dp2 = min(dp0_temp, dp1_temp) + costs[i-1][2];
        }
        return min(dp0, min(dp1, dp2));
    }
};

int main(){

    return 0;
}