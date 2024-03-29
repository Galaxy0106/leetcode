#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void debug(vector<vector<int>> &v){
    for(int i = 0;i < v.size();i++){
        for(int j = 0;j < v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        // 初始化 base case
        dp[0][0] = true;
        for(int j = 1;j <= n;j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-2]; 
            }
        }

        // 状态转移方程
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    if(p[j-1] == '*'){
                        dp[i][j] = dp[i][j-2];
                        if(s[i-1] == p[j-2] || p[j-2] == '.'){
                            dp[i][j] = dp[i][j] || dp[i-1][j];
                        }
                    }
                }
                // debug(dp);
                // cout << "\n";
            }
            
        }
        return dp[m][n];
    }
};

using namespace std;

int main(){
    Solution sol;
    string s = "aa";
    string p = "a*";
    cout << sol.isMatch(s, p);
    return 0;
}