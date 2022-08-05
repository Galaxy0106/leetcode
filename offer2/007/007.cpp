#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if(len < 3){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0;i < len;i++){
            vector<vector<int>> res2;
            int k = nums[i];
            int l = i + 1, r = len - 1;
            if(r - l < 2)
                break;
            while(l < r){
                if(nums[l] + nums[r] > -k){
                    int temp = nums[r];
                    r--;
                    while(l < r){
                        if(nums[r] != temp)
                            break;
                        r--;
                    }
                }
                else if(nums[l] + nums[r] < -k){
                    int temp = nums[l];
                    l++;
                    while(l < r){
                        if(nums[l] != temp)
                            break;
                        l++;
                    }
                }
                else{
                    res2.push_back({nums[l], nums[r]});
                    int temp1 = nums[l];
                    int temp2 = nums[r];
                    l++, r--;
                    while(l < r){
                        if(nums[l] != temp1)
                            break;
                        l++;
                    }
                    while(l < r){
                        if(nums[r] != temp2)
                            break;
                        r--;
                    }
                }
            }
            for(auto sub: res2){
                sub.push_back(nums[i]);
                res.push_back(sub);
            }
            while(i < len - 1){
                if(nums[i] != nums[i+1])
                    break;
                i++;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-1, -1, 0, 1, 2, 4};
    sol.threeSum(nums);
    return 0;
}