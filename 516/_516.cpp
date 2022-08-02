#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        // 定义状态
        vector<vector<int>> dp(len, vector<int>(len));
        // 初始化 base case
        for(int i = 0;i < len;i++){
            dp[i][i] = 1;
        }
        // 状态转换
        for(int i = len-1;i >=0;i--){
            for(int j = i+1;j < len;j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][len-1];
    }
};

int main(){

    return 0;
}