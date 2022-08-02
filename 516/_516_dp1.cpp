#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        // 定义状态 并 初始化 base case
        vector<int> dp(len, 1);
        // 状态转换
        for(int i = len-2;i >=0;i--){
            int pre = 0;
            for(int j = i+1;j < len;j++){
                int temp = dp[j];
                if(s[i] == s[j]){
                    dp[j] = pre + 2;
                }
                else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
                pre = temp;
            }
        }
        return dp[len-1];
    }
};

int main(){

    return 0;
}