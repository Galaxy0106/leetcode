#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> preSum;
    Solution(vector<int>& w) {
        int n = w.size();
        preSum.resize(n + 1);
        preSum[0] = 0;
        for(int i = 0;i < w.size();i++){
            preSum[i+1] = preSum[i] + w[i];
        }
    }
    
    int pickIndex() {
        int n = preSum.size();
        int target = rand() % preSum.back() + 1;

        // 二分查找左边界
        int left = 1, right = preSum.size();
        while(left <= right){
            int mid = left + (right - left)/2;
            if(preSum[mid] >= target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

int main(){
    vector<int> w = {4, 2};
    Solution* obj = new Solution(w);
    cout << obj->pickIndex();
    cout << obj->pickIndex();
    cout << obj->pickIndex();
    cout << obj->pickIndex();
    cout << obj->pickIndex();
    cout << obj->pickIndex();
    cout << obj->pickIndex();
    cout << obj->pickIndex();    
    return 0;
}