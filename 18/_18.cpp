#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printIndent(int n){
    for(int i = 0;i < n;i++){
        cout << "\t";
    }
}

// void printRes(vector<vector<int>>& res){
//     for(int i = 0;;)
// }

class Solution {
public:
    vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, long long target){
        // printIndent(count++);
        // cout << start << endl;
        vector<vector<int>> res;       
        int len = nums.size();
        if(len < 2 || n > len){
            return res;
        }
        if(n == 2){
            // n == 2
            // printIndent(--count);
            int l = start, r = len - 1;
            while(l < r){
                if((long long)nums[l] + nums[r] > target){
                    int temp = nums[r];
                    while(l < r && nums[--r] == temp){}
                }
                else if((long long)nums[l] + nums[r] < target){
                    int temp = nums[l];
                    while(l < r && nums[++l] == temp){}
                }
                else{
                    vector<int> ans;
                    ans.push_back(nums[l]);
                    ans.push_back(nums[r]);
                    res.push_back(ans);
                    int temp1 = nums[l], temp2 = nums[r];
                    l++, r--;
                    while(l < r){
                        if(nums[l] != temp1)
                            break;
                        l++;
                    }
                    while(l < r){
                        if(nums[r] != temp2);
                            break;
                        r--;
                    }
                }
            }
            // return res;
        }
        else{
            // n > 2
            for(int i = start;i < nums.size();i++){
                vector<vector<int>> subs = nSumTarget(nums, n-1, i+1, target - nums[i]);
                for(vector<int> sub : subs){
                    sub.push_back(nums[i]);
                    res.push_back(sub);
                }
                int temp = nums[i];
                i++;
                while(i < nums.size()){
                    if(nums[i] != temp)
                        break;
                    i++;
                };
                i--;
            }
            // return res;
        }
        // cout << "return" << endl;
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // for(int i = 0;i < nums.size();i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        res = nSumTarget(nums, 4, 0, (long long)target);
        return res;
    }
};

int main(){
    Solution sol;
    // vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> ans = sol.fourSum(nums, 0);
    cout << INT_MAX;
    for(int i = 0;i < ans.size();i++){
        cout << "[ ";
        for(int j = 0;j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}