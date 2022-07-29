#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != 0){
                swap(nums[index], nums[i]);
                index++;
            }
        }
        return;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12, 0, 2, 0, 6, 7, 8, 0, 10};
    sol.moveZeroes(nums);
    for(auto num : nums){
        cout << num << " ";
    }
    return 0;
}