#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    void debug(vector<vector<int>>& dp){
        for(int i = 0;i < dp.size();i++){
            for(int j = 0;j < dp[i].size();j++){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }

    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        // 定义状态
        vector<vector<int> > dp(n + 1, vector<int>(V+1));
        // 初始化 base case
        for(int i = 0;i <= n;i++){
            dp[i][0] = 0;
        }
        for(int j = 0;j <= V;j++){
            dp[0][j] = 0;
        }
        // 状态转移
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= V;j++){
                if(j - vw[i-1][0] < 0){
                    // 只能选择不放
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - vw[i-1][0]] + vw[i-1][1]);
                }
            }
        }
        return dp[n][V];  
    }
};

int main(){
    vector<vector<int>> vw = {{2, 7},{0, 9}};
    Solution sol;
    cout << sol.knapsack(10, 2, vw);
    return 0;
}