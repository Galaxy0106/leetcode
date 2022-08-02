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
        vector<bool> dp(sum/2 + 1);
        // 初始化 base case
        dp[0] = true;
        // for(int j = 0;j <= sum/2;j++){
        //     dp[j] = true;
        // }

        // 状态转移
        for(int i = 1;i <= m;i++){
            for(int j = sum/2;j >= 0;j--){
                if(j - nums[i-1] >= 0){
                    dp[j] = dp[j] || dp[j - nums[i-1]];
                }
            }
        }
        return dp[sum/2];
    }
};

int main(){
    vector<int> nums = {1,2,5}; 
    Solution sol;
    cout << sol.canPartition(nums);
    return 0;
}