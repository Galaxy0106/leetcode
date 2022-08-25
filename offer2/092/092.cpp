#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // 定义dp数组, dp[n]表示0 -（n-1）需要的最小翻转次数
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i = 1;i <= n;i++){
            if(s[i-1] == '0'){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
            }
            else{
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            }
        }
        return min(dp[n][0], dp[n][1]);
    }
};

int main(){


    return 0;
}