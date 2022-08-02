#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        // 定义状态
        vector<int> dp(amount+1);
        // 初始化 base case
        dp[0] = 1;

        for(int j = 1;j <= amount;j++){
            dp[j] = 0; 
        }

        // 状态转换
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= amount;j++){
                if(j - coins[i-1] >= 0){
                    dp[j] = dp[j] + dp[j - coins[i-1]];
                }
            }
        }
        return dp[amount];
    }
};


int main(){

    return 0;
}