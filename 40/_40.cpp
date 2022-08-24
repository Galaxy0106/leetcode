#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void helper(int index, int target, vector<int>& v, vector<int>& candidates){
        if(target < 0)
            return;
        if(target == 0){
            res.push_back(v);
            return;
        }

        if(index < candidates.size()){
            // 不选
            int nextIndex = index + 1;
            while(nextIndex < candidates.size()){
                if(candidates[nextIndex] != candidates[index])
                    break; 
                nextIndex++;
            }

            helper(nextIndex, target, v, candidates);

            // 选
            v.push_back(candidates[index]);
            helper(index + 1, target - candidates[index], v, candidates);
            v.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        helper(0, target, v, candidates);
        return res;
    }
};

int main(){
    Solution sol;

    return 0;
}