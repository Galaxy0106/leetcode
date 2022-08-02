#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 定义状态
        // 初始化 base case
        int dp0 = 0, dp1 = INT_MIN;
        // 状态转换
        for(int i = 1;i <= n;i++){
            dp0 = max(dp0, dp1 + prices[i-1]);
            dp1 = max(dp1, -prices[i-1]);
        }
        return dp0;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    cout << sol.maxProfit(prices);
    return 0;
}