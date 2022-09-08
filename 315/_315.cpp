#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> temp;
    vector<pair<int, int>> vp;
    vector<int> res;
    void merge(vector<pair<int, int>>& vp, int lo, int mid, int hi) {
        for(int i = lo;i <= hi;i++){
            temp[i] = vp[i];
        }
        int p1 = lo, p2 = mid+1;
        int p = lo;
        while(p <= hi){
            if(p1 == mid+1){
                vp[p] = temp[p2++];
            }
            else if(p2 == hi+1){
                vp[p] = temp[p1++];
                res[vp[p].second] += p2 - mid - 1;
            }
            else if(vp[p1].first <= vp[p2].first){
                vp[p] = temp[p1++];
                res[vp[p].second] += p2 - mid - 1;
            }
            else{
                vp[p] = temp[p2++];
            }
            p++;
        }
        return;
    }

    void mergeSort(vector<pair<int, int>>& vp, int lo, int hi) {
        if(lo == hi)
            return;
        int mid = lo + (hi-lo)/2;
        mergeSort(vp, lo, mid);
        mergeSort(vp, mid+1, hi);
        merge(vp, lo, mid, hi);
    }

    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size() == 0)
            return res;
        int n = nums.size();
        res.resize(n, 0);
        for(int i = 0;i < n;i++){
            vp.push_back({nums[i], i});
        }
        temp.resize(n);
        mergeSort(vp, 0, n-1);
        return res;
    }
};

int main(){
    vector<int> nums = {1, 9, 7, 8, 5};
    Solution sol;
    vector<int> res = sol.countSmaller(nums); 
    for(auto r : res){
        cout << r << " ";
    }
    return 0;
}