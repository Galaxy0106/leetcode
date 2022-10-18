#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> dp(n+1, 0);
        // 初始化 base case
        dp[0] = 1, dp[1] = 1;
        for(int i = 2;i <= n;i++){
            char c = s[i-1], d = s[i-2];
            if(c >= '1' && c <= '9'){
                dp[i] += dp[i-1];
            }
            if(d == '1' || (d == '2' && c <= '6')){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    cout << sol.numDecodings("111111111111111111111") << endl;
    return 0;
}