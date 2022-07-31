#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        ans[0] = 0;
        for(int i = 1;i <= n;i++){
            if(i%2){
                ans[i] = ans[i-1] + 1;
            }
            else{
                ans[i] = ans[i/2];
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = sol.countBits(5);
    for(auto num : nums){
        cout << num << " ";
    }
    return 0;
}