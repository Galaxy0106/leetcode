#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 求和
        int sum = 0;
        int m = nums.size();
        for(auto num : nums){
            sum += num;
        }
        if(sum%2){
            return false;
        }
        // 定义状态
        vector<vector<bool>> dp(m+1, vector<bool>(sum/2 + 1));
        // 初始化 base case
        dp[0][0] = true;
        for(int i = 1;i <= m;i++){
            dp[i][0] = true;
        }

        // for(int j = 1;j <= sum/2;j++){
        //     dp[0][j] = false;
        // }

        // 状态转移
        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= sum/2;j++){
                if(j - nums[i-1] < 0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[m][sum/2];
    }
};

// int main(){

//     return 0;
// }