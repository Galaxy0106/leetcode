#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 初始化 base case
        int dp0 = 0, dp1 = INT_MIN;
        // 状态转换
        int dp_pre = 0;
        for(int i = 1;i <= n;i++){
            int temp = dp0;
            dp0 = max(dp0, dp1 + prices[i-1]);
            dp1 = max(dp1, dp_pre - prices[i-1]);
            dp_pre = temp;
        }
        return dp0;
    }
};

int main(){
    vector<int> prices = {1,2,3,0,2};
    Solution sol;
    cout << sol.maxProfit(prices);
    return 0;
}