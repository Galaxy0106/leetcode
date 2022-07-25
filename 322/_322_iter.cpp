#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount ;i++){
            int res = INT_MAX;
            for(int coin : coins){
                if(i - coin < 0)
                    continue;
                if(dp[i - coin] == INT_MAX)
                    continue; 
                res = min(res, dp[i - coin] + 1);
            }
            if(res != INT_MAX)
                dp[i] = res;
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};

int main(){
    Solution sol;
    vector<int> coins = {2};
    cout << sol.coinChange(coins, 3);
    return 0;
}