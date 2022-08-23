#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_bound, right_bound;
        // 寻找左边界
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                right = mid - 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        if(left == nums.size())
            return 0;
        if(nums[left] == target)
            left_bound = left;   
        else
            return 0;
        left = 0;
        right = nums.size() - 1;
        // 寻找右边界
        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if(left - 1 < 0)
            return 0;
        if(nums[left-1] == target)
            right_bound = left - 1;
        else
            return 0;
        return right_bound - left_bound + 1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    cout << sol.search(nums, 8);
}