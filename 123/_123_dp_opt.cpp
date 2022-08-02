#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 定义状态
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2)));
        // cout << dp.size() << " " << dp[0].size() << " " << dp[0][0].size();
    
        int dpi10 = 0, dpi11 = INT_MIN;
        int dpi20 = 0, dpi21 = INT_MIN;


        // 状态转换
        for(int i = 1;i <= n;i++){
            dpi10 = max(dpi10, dpi11 + prices[i-1]);
            dpi11 = max(dpi11, -prices[i-1]);            

            dpi20 = max(dpi20, dpi21 + prices[i-1]);
            dpi21 = max(dpi21, dpi10 - prices[i-1]);
        }
        return dpi20;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    sol.maxProfit(prices);
    return 0;
}