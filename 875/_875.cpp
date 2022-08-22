#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int f(vector<int>& piles, int k){
        // 返回 速度 为 k 时 吃完的时间
        int res = 0;
        for(int i = 0;i < piles.size();i++){
            int cur = (piles[i] % k) ? piles[i]/k + 1: piles[i]/k;
            res += cur;
        }
        return res;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int res = -1;
        int max_k = INT_MIN;
        for(int i = 0;i < piles.size();i++){
            max_k = max(max_k, piles[i]);
        }
        int left = 1, right =  max_k;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(f(piles, mid) <= h){
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
    Solution sol;
    vector<int> piles ={312884470};
    int h = 312884469;
    cout << INT_MAX;
    cout << sol.minEatingSpeed(piles, h);
    return 0;
}