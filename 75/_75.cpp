#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        for(int i = 0;i <= r;i++){            
            while(nums[i] == 2 && i <= r){
                swap(nums[i], nums[r]);
                r--;
            }
            if(nums[i] == 0){
                swap(nums[i], nums[l]);
                l++;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 0};
    sol.sortColors(nums);
    for(int i = 0;i < nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}