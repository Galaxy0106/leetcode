#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // 定义dp数组
        vector<int> dp(n+1, INT_MAX);
        // 初始化 base case
        dp[0] = 0;
        // 状态转移
        for(int i = 1;i <= n;i++){
            int j = 1;
            while(pow(j, 2) <= i){
                int x = pow(j, 2);
                dp[i] = min(dp[i - x] + 1, dp[i]);
                j++;
            }
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    cout << sol.numSquares(12);
    return 0;
}