#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> memo;

    int coinChange(vector<int>& coins, int amount) {
        for(int i = 0;i <= amount; i++){
            memo.push_back(-666);
        }
        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int amount) {
        if(amount < 0)
            return -1;

        if(amount == 0)
            return 0;
        
        if(memo[amount] != -666)
            return memo[amount];

        int res = INT_MAX;
        for(int coin : coins){
            int subProblem = dp(coins, amount - coin);
            if(subProblem == -1)
                continue;
            res = min(res, subProblem + 1);
        }
        if(res == INT_MAX)
            memo[amount] = -1;
        else
            memo[amount] = res;
        
        return memo[amount];
    }

};

// int main(){
//     Solution sol;
//     vector<int> coins = {1, 2, 5};
//     cout << sol.coinChange(coins, 11);
//     return 0;
// }