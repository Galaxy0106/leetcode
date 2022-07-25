#include <iostream>

using namespace std;

class Solution {
public:
    int helper(int memo[], int n){
        if(memo[n] != 0)
            return memo[n];
        if(n == 0 || n == 1){
            memo[n] = n;
            return n;
        }
        else{
            memo[n] = helper(memo, n-1) + helper(memo, n-2);
            return memo[n];
        }
    }

    int fib(int n) {
        int* memo = new int[n + 1]();
        return helper(memo, n);
    }
};

int main(){
    Solution sol;
    cout << sol.fib(20);
    return 0;
}