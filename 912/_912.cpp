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

    void quickSort(vector<int>& nums, int lo, int hi){
        if(lo >= hi)
            return;
        int p = partition(nums, lo, hi);
        quickSort(nums, lo, p-1);
        quickSort(nums, p+1, hi);
        return;
    }

    void shuffle(vector<int>& nums){
        int n = nums.size();
        for(int i = 0;i < n;i++){
            int j = rand() % (n-i) + i;
            swap(nums[i], nums[j]);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        shuffle(nums);
        quickSort(nums, 0, n-1);
        return nums;
    }
};

int main(){
    vector<int> nums = {5, 1, 1, 2, 0, 0};
    Solution sol;
    // sol.shuffle(nums);
    // for(int i = 0;i < nums.size();i++){
    //     cout << nums[i] << " ";
    // }

    vector<int> res = sol.sortArray(nums);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}