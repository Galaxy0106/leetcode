#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int min3(int a, int b, int c){
        return min(min(a, b), c);
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // 定义dp数组
        vector<vector<int>> dp = vector<vector<int>>(m+1, vector<int>(n+1));
        // 初始化 base case
        dp[0][0] = 0;
        for(int i = 1;i <= m;i++){
            dp[i][0] = i;
        }
        for(int j = 1;j <= n;j++){
            dp[0][j] = j;
        }
        // 状态转移方程
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    Solution sol;
    cout << sol.minDistance("intention", "execution");
    return 0;
}