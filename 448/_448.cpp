#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0)
                continue;
            if(nums[i] == i+1){
                // 是正确的位置
                continue;
            }
            else{
                // 不是正确的位置
                int k = nums[i];
                nums[i] = 0;
                while(nums[k-1] != k){
                    int temp = nums[k-1];
                    nums[k-1] = k;
                    k = temp;
                    if(k == 0)
                        break;
                }
            }
        }

        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0)
                res.push_back(i+1);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res = sol.findDisappearedNumbers(nums);
    for(auto r : res){
        cout << r << " ";
    }
    return 0;
}