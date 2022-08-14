#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<int> bitSum(32, 0);
        // 给数组赋值
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 32;j++)
                bitSum[j] += (nums[i] >> (31-j)) & 1;
        }
        // 求结果
        for(int i = 0;i < 32;i++){
            res = (res << 1) + (bitSum[i]%3);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 2, 3, 2};
    cout << sol.singleNumber(nums);
    return 0;
}