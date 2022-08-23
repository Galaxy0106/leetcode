#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int res = -1;
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(mid - 1 < 0){
                if(nums[mid+1] == nums[mid]){
                    left = mid + 1;
                    continue;
                }
                else{
                    res = mid;
                    break;
                }                
            }
            
            
            if(mid + 1 == nums.size()){
                if(nums[mid-1] == nums[mid]){
                    right = mid - 1;
                    continue;
                }
                else{
                    res = mid;
                    break;
                }
            }

            if(nums[mid + 1] == nums[mid]){
                // 左边
                if(mid % 2 == 0){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
            else if(nums[mid - 1] == nums[mid]){
                if(mid % 2 == 0){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                res = mid;
                break;
            }
        }
        return nums[res];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,3,7,7,10,11,11};
    cout << sol.singleNonDuplicate(nums);
    return 0;
}