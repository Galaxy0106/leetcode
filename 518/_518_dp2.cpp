#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        // 定义状态
        vector<vector<int>> dp(m+1, vector<int>(amount+1));
        // 初始化 base case
        for(int i = 0;i <= m;i++){
            dp[i][0] = 1;
        }

        for(int j = 1;j <= amount;j++){
            dp[0][j] = 0; 
        }

        // 状态转换
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= amount;j++){
                if(j - coins[i-1] < 0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j - coins[i-1]];
                }
            }
        }
        return dp[m][amount];
    }
};


// int main(){

//     return 0;
// }