#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // 定义状态
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2)));
        // cout << dp.size() << " " << dp[0].size() << " " << dp[0][0].size();
        // 初始化 base case
        for(int j = 0;j <= k;j++){
            dp[0][j][0] = 0;
            dp[0][j][1] = INT_MIN;           
        }

        for(int i = 0;i <= n;i++){
            dp[i][0][0] = 0; 
            dp[i][0][1] = INT_MIN;
        }
        // 状态转换
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= k;j++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i-1]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i-1]);
            }
        }
        return dp[n][k][0];        
    }
};

int main(){

    return 0;
}