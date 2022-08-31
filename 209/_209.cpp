#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 求和
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
        }
        if(sum < target)
            return 0;
        int res = nums.size();
        int index1 = 0;
        int index2 = nums.size() - 1;
        while(index1 <= index2){            
            if(nums[index1] > nums[index2] && sum - nums[index2] >= target){
                // 移动index2
                sum -= nums[index2];
                index2--;
            }
            else if(nums[index1] <= nums[index2] && sum - nums[index1] >= target){
                // 移动index1
                sum -= nums[index1];
                index1++;
            }
            else{
                res = index2 - index1 + 1;
                break;
            }
        }
        return res;
    }
};

// int main(){
//     Solution sol;
//     vector<int> nums = {5,1,3,5,10,7,4,9,2,8};
//     int target = 15;
//     cout << sol.minSubArrayLen(target, nums);
//     return 0;
// }