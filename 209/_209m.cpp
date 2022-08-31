#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int left = 0, right = 0;
        int sum = 0;
        while(right < nums.size()){
            // 增大窗口
            int k1 = nums[right];
            right++;
            sum += k1;
            
            // 缩小窗口
            while(sum >= target){
                res = min(res, right - left);
                int k2 = nums[left];
                left++;
                sum -= k2;
            }
        }
        return (res == INT_MAX) ? 0 : res;
    }
};

int main(){
    Solution sol;

    return 0;
}