#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        int num3 = n/3;
        if(n - num3*3 == 1)
            num3--;
        int num2 = (n - num3*3)/2;
        return int(pow(3, num3) * pow(2, num2));
    }
};

int main(){
    Solution sol;
    cout << sol.integerBreak(10);
    return 0;
}