#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int count;
    vector<int> temp;
    void merge(vector<int>& nums, int lo, int mid, int hi) {
        for(int i = lo;i <= hi;i++){
            temp[i] = nums[i];
        }
        int j = mid + 1;
        for(int i = lo;i <= mid;i++){
            while(j <= hi &&  (long long)nums[i] > 2 * (long long)nums[j]){
                j++;
            }
            count += (j - mid - 1);
        }
        int p1 = lo, p2 = mid + 1;
        int p = lo;
        while(p <= hi) {
            if(p1 == mid+1){
                nums[p++] = temp[p2++];
            }
            else if(p2 == hi+1){
                nums[p++] = temp[p1++];
            }
            else if(temp[p1] <= temp[p2]){
                nums[p++] = temp[p1++];
            }
            else{
                nums[p++] = temp[p2++];
            }
        }
        return;
    }

    void mergeSort(vector<int>& nums, int lo, int hi) {
        if(lo >= hi)
            return;
        int mid = lo + (hi-lo)/2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid+1, hi);
        merge(nums, lo, mid, hi);
        return;
    }

    int reversePairs(vector<int>& nums) {
        count = 0;
        int n = nums.size();
        temp.resize(n);
        mergeSort(nums, 0, n-1);
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 4, 3, 5, 1};
    cout << sol.reversePairs(nums) << endl;
    return 0;
}