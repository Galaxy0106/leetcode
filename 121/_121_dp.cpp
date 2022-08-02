#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 定义状态
        vector<vector<int>> dp(n+1, vector<int>(2));
        // 初始化 base case
        dp[0][0] = 0, dp[0][1] = INT_MIN;
        // 状态转换
        for(int i = 1;i <= n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], -prices[i-1]);
        }
        return dp[n][0];
    }
};

// int main(){
//     vector<int> prices = {7,1,5,3,6,4};
//     Solution sol;
//     cout << sol.maxProfit(prices);
//     return 0;
// }