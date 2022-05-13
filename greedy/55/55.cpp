#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        bool ans = false;
        int fur_pos = nums[0];
        for(int i = 0;i <= fur_pos;i++){
            if(i + nums[i] > fur_pos){
                fur_pos = i + nums[i];
            }

            if(fur_pos >= nums.size() - 1){
                ans = true;
                break;
            }    
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> input = {0,2,3};
    bool ans = sol.canJump(input);
    cout << ans;
    return 0;
}