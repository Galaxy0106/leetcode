#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSquareSum(int n){
        int res = 0;
        while(n){
            res += (n%10)*(n%10);
            n = n/10;
        }
        return res;
    }

    bool isHappy(int n) {
        int num1 = getSquareSum(n);
        int num2 = getSquareSum(getSquareSum(n));
        while(num1 != num2){
            num1 = getSquareSum(num1);
            num2 = getSquareSum(getSquareSum(num2));
        }
        return num1 == 1;
    }
};

int main(){
    Solution sol;
    cout << sol.isHappy(19);
    return 0;
}