#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 定义dp数组
        int len = nums.size();
        vector<int> dp(len);
        dp[0] = 1;
        for(int i = 1;i < len;i++){
            int k = 0;
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j]){
                    k = max(k, dp[j]);
                }
            }
            dp[i] = k+1;
        }
        int res = 0;

        // for(int i = 0;i < len;i++){
        //     cout << dp[i] << " ";
        // }

        for(int i = 0;i < len;i++){
            if(dp[i] > res)
                res = dp[i];
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    cout << sol.lengthOfLIS(nums);
    return 0;
}