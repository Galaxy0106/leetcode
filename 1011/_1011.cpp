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


    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int max_w = INT_MIN;
        for(int i = 0;i < weights.size();i++){
            sum += weights[i];
            max_w = max(max_w, weights[i]);
        }
        int left = max_w, right = sum;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(f(weights, mid) <= days){
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
    vector<int> weights ={1,2,3,1,1};
    cout << sol.f(weights, 2);
    return 0;
}