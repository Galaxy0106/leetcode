#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi){
        int pivot = nums[lo];
        int i = lo+1, j = hi;
        while(i <= j){
            while(i <= j && nums[i] <= pivot){
                i++;
            }
            while(i <= j && nums[j] > pivot){
                j--;
            }
            if(i >= j)
                break;
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n - k;
        int pos = -1;
        int lo = 0, hi = n-1;
        while(pos != target){
            pos = partition(nums, lo, hi);
            if(pos > target){
                hi = pos - 1;
            }
            else if(pos < target){
                lo = pos + 1;
            }
            else{
                break;
            }
        }
        return nums[pos];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    cout << sol.findKthLargest(nums, 2);
    return 0;
}