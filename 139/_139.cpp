#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 定义状态数组
        int n = s.size();
        vector<bool> dp(n+1, false);
        // 初始化 base case
        dp[0] = true;
        // 状态转移
        for(int i =0;i <= n;i++){
            if(!dp[i])
                continue;
            for(auto& word : wordDict){
                if(i + word.size() <= n && s.substr(i, word.size()) == word){
                    dp[i + word.size()] = true;
                }
            }
        }
        return dp[n];
    }
};

int main(){

    return 0;
}