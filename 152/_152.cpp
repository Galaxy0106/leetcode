#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int maxV = 1, minV = 1;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] < 0){
                int temp = maxV;
                maxV = minV;
                minV = temp;
            }
            maxV = max(maxV * nums[i], nums[i]);
            minV = min(minV * nums[i], nums[i]);
            res = max(res, maxV);
        }
        return res;        
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,-2,4};
    cout << sol.maxProduct(nums);
    return 0;
}