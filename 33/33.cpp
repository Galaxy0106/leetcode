#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res;
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                res = mid;
                break;
            }
            if(nums[mid] >= nums[left]){
                // 左半边有序
                if(nums[left] < target && nums[mid] > target){
                    right = mid;
                }
                else if(nums[left] == target){
                    res = left;
                    break;
                }
                else{
                    // target 在右半部分
                    left = mid + 1;
                }
            }
            else{
                // 右半边有序
                if(nums[right] > target && nums[mid] < target){
                    left = mid + 1;
                }
                else if(nums[right] == target){
                    res = right;
                    break;
                }
                else{
                    // target 在左半部分
                    right = mid;
                }
            }
        }        
        return res;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.search(nums, 0);
    return 0;
}