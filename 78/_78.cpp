#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& v, int k){
        if(k == nums.size()){
            ans.push_back(v);
            return;
        }

        // 不加入
        dfs(ans, nums, v, k+1);

        // 加入
        v.push_back(nums[k]);
        dfs(ans, nums, v, k+1);
        v.pop_back();

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        dfs(ans, nums, v, 0);
        return ans;
    }
};

using namespace std;

int main(){
    Solution s;
    vector<vector<int> > res;
    vector<int> nums = {1,2,3};
    res = s.subsets(nums);
    for (size_t i = 0; i < res.size(); i++)
    {
        for(size_t j = 0;j < res[i].size(); j++){
            cout<< res[i][j] << " ";
        }
        cout<<endl;
    }
    
    return 0;
}