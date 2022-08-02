#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tops;
        int res = 0;
        tops.push_back(nums[0]);
        for(int i = 1;i < nums.size();i++){
            // 查找要放的堆
            int left = 0;
            int right = tops.size() - 1;
            while(left < right){
                int mid = (left + right)/2;
                if(nums[i] > tops[mid]){
                    left = mid + 1;
                }
                else if(nums[i] < tops[mid]){
                    right = mid;
                }
                else{
                    left = mid + 1;
                }
            }

            

        }

    }
};

int main(){

    return 0;
}