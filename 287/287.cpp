#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast)
                break;
        }
        // 求环的长度
        int k = slow;
        int len = 0;
        while(1){
            k = nums[k];
            len++;
            if(k == slow)
                break;
        }
        // 求环的起始结点        
        slow = 0, fast = 0;
        while(len--){
            fast = nums[fast];
        }
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << sol.findDuplicate(nums);
    return 0;
}