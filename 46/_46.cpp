#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<bool>& is_vis, vector<int>& path){
        if(path.size() == nums.size()){
            res.push_back(path);
        }
        for(int i = 0;i < nums.size();i++){
            if(!is_vis[i]){
                is_vis[i] = true;
                path.push_back(nums[i]);
                backtrack(nums, is_vis, path);
                is_vis[i] = false;
                path.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> is_vis(n, false);
        vector<int> path;
        backtrack(nums, is_vis, path);
        return res;
    }
};

int main(){

    return 0;
}