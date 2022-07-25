#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1)
            return n;
        int dp;
        int dp1 = 0, dp2 = 1; 
        for(int i = 2; i <= n;i++){
            dp = dp1 + dp2;
            dp1 = dp2; dp2 = dp; 
        }
        return dp;
    }
};

int main(){
    Solution sol;
    cout << sol.fib(20);
    return 0;
}