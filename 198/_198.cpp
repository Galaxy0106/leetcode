#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 定义dp数组
        int m = nums.size();
        vector<int> dp(m + 1, 0);
        // 初始化 base case
        dp[0] = 0;
        for(int i = 1;i <= m;i++){
            // 偷 或 不偷
            if(i >= 2)
                dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
            else
                dp[i] = nums[i-1]; 
        }
        return dp[m];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << sol.rob(nums);
    return 0;
}