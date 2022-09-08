#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<ll> temp;
    int res;
    int lower;
    int upper;
    void merge(vector<ll>& nums, int lo, int mid, int hi) {
        for(int i = lo;i <= hi;i++){
            temp[i] = nums[i];
        }
        int start = mid+1, end = mid+1;
        for(int i = lo;i <= mid;i++){
            // 找 start
            while(start <= hi && nums[start] - nums[i] < lower) {
                start++;
            }
            // 找 end
            while(end <= hi && nums[end] - nums[i] <= upper) {
                end++;
            }
            res += (end - start);
        }
        // 合并
        int p1 = lo, p2 = mid+1;
        int p = lo;
        while(p <= hi){
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

    void mergeSort(vector<ll>& nums, int lo, int hi) {
        if(lo == hi)
            return;
        int mid = lo + (hi-lo)/2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid+1, hi);
        merge(nums, lo, mid, hi);
        return;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<ll> preSum(n+1, 0);
        //初始化前缀和数组
        for(int i = 1;i <= n;i++){
            preSum[i] = preSum[i-1] + nums[i-1];
        }
        temp.resize(n+1);
        res = 0;
        this->lower = lower;
        this->upper = upper;
        mergeSort(preSum, 0, n);
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;
    cout << sol.countRangeSum(nums, lower, upper) << endl;
    return 0;
}