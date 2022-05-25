#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i = 0;i < nums.size();i++){
            if(dq.front() == i - k)
                dq.pop_front();
            int cur = nums[i];
            while(!dq.empty() && nums[dq.back()] <= cur)
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);   
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> ans;
    Solution sol;
    ans = sol.maxSlidingWindow(nums, 3);
    for(auto a : ans){
        cout << a << " ";
    }
    return 0;
}