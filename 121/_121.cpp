#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX;
        int res = 0;
        for(int i = 0;i < prices.size();i++){
            res = max(res, prices[i] - minP);
            if(minP > prices[i])
                minP = prices[i];
        }
        return res;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution sol;
    cout << sol.maxProfit(prices);
    return 0;
}