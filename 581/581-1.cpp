#include<bits/stdc++.h>

using namespace std;

// 双指针
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> numscpy(nums);
        sort(numscpy.begin(), numscpy.end());
        int left = 0;
        int right = nums.size() - 1;
        while(left < nums.size()){
            if(nums[left] != numscpy[left]){
                break;
            }
            left++;
        }

        while(right >= 0){
            if(nums[right] != numscpy[right]){
                break;
            }
            right--;
        }
        return right - left + 1;
    }
};

int main(){
    vector<int> input = {1,3,2,4,5};
    Solution sol;
    int ans = sol.findUnsortedSubarray(input);
    cout << ans;
    return 0;
}