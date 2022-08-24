#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void helper(int k, vector<int>& v, vector<int>& nums, vector<bool>& visited){
        if(k == nums.size()){
            res.push_back(v);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(!visited[i]){
                if(i > 0 && nums[i] == nums[i-1] && visited[i-1]){
                    break;
                }
                v.push_back(nums[i]);
                visited[i] = true;
                helper(k+1, v, nums, visited);
                v.pop_back();
                visited[i] = false;
            }
        }
        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<bool> visited(n, false); 
        sort(nums.begin(), nums.end());
        helper(0, v, nums, visited);
        return res;
    }
};

int main(){
    Solution sol;

    return 0;
}