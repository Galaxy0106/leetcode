#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len);
        ans[0] = 1;
        for(int i = 1;i < nums.size();i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        int R = 1;
        for(int i = len - 1;i >= 0;i--){
            ans[i] = ans[i] * R;
            R = R * nums[i];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> ans = sol.productExceptSelf(nums);
    for(int i = 0;i < ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}