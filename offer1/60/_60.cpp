#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res;
        // 定义 dp 数组
        vector<vector<double>> dp(n+1, vector<double>(6*n + 1, 0));
        // 初始化 base case
        for(int i = 1;i <= 6;i++){
            dp[1][i] = 1/6.0;
        }
        // 状态转移
        for(int i = 2;i <= n;i++){
            for(int j = 1;j <= 6*n;j++){
                double sum = 0;
                for(int k = 1;k <= 6;k++){
                    if(j - k > 0){
                        sum += dp[i-1][j-k]/6.0;
                    }
                }
                dp[i][j] = sum;
            }
        }
        for(int i = 0;i < dp[n].size();i++){
            if(dp[n][i] > 0){
                res.push_back(dp[n][i]);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<double> res = sol.dicesProbability(2);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}