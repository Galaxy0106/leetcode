#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int res;
    void dfs(vector<int>& nums, int index, int target, int sum, unordered_map<int, int>& umap){
        // if(umap.count(target - sum))
        
        if(index == nums.size()){ 
            if(sum == target)
                res++;
            return;
        } 
        // 加
        // dfs(nums, index+1, target, sum + nums[index]);
        // 减
        // dfs(nums, index+1, target, sum - nums[index]);
        return;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        res = 0;
        unordered_map<int, int> umap;
        // dfs(nums, 0, target, 0);
        return res;
    }
};

// int main(){
//     Solution sol;
//     vector<int> nums = {1, 1, 1, 1, 1};
//     cout << sol.findTargetSumWays(nums, 3);
//     return 0;
// }