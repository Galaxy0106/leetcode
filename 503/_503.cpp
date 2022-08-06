#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for(int i = 2*n-1;i >= 0;i--){
            while(!stk.empty() && nums[i%n] >= stk.top()){
                stk.pop();
            }
            if(stk.empty()){
                res[i%n] = -1;
            }
            else{
                if(res[i%n] == -1)
                    res[i%n] = stk.top();
            }
            stk.push(nums[i%n]);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 3};
    vector<int> res = sol.nextGreaterElements(nums);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}