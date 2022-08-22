#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        vector<int> dp(n+1);
        int mod = 1000000007;
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            if(i == 1){
                dp[i] = 1;
                continue;
            }
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    cout << sol.numWays(0);
    return 0;
}