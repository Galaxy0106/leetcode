#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, vector<int>& temp, int index, int sum, int target){
        if(index == candidates.size())
            return;
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        dfs(candidates, temp, index+1, sum, target);
        if(sum < target){
            temp.push_back(candidates[index]);
            dfs(candidates, temp, index, sum + candidates[index], target);
            temp.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        dfs(candidates, temp, 0, 0, target);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    sol.combinationSum(candidates, target);
    for(auto single_ans : sol.ans){
        for(auto num : single_ans){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}