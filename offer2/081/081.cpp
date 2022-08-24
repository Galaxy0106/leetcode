#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void helper(int i, int sum, int target, vector<int>& v, vector<int>& candidates) {
        if(sum > target)
            return;
        if(sum == target){
            res.push_back(v);
            return;
        }
        if(i < candidates.size()){
            helper(i+1, sum, target, v, candidates);

            v.push_back(candidates[i]);
            helper(i, sum + candidates[i], target, v, candidates);
            v.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        helper(0, 0, target, v, candidates);
        return res;
    }
};

int main(){
    Solution sol;

    return 0;
}