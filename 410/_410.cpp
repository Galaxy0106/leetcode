#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(vector<int>& weights, int x) {
        int res = 0;
        int cur = 0;
        for(int i = 0;i < weights.size();i++){
            cur += weights[i];
            if(cur == x){
                res++;
                cur = 0;
            }
            if(cur > x){
                res++;
                cur = weights[i];
            }
        }

        return cur ? res + 1: res;
    }

    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int max_w = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            max_w = max(max_w, nums[i]);
        }
        int left = max_w, right = sum;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(f(nums, mid) <= m){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};

int main(){


    return 0;
}