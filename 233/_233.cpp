#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int high = n / 10;
        int low = 0;
        int cur = n % 10;
        int digit = 1;
        int res = 0;
        while(high != 0 || cur != 0){
            if(cur == 0){
                res += high * digit;
            }
            else if(cur == 1){
                res += high * digit + low + 1;
            }
            else{
                res += high* digit + digit;
            }
            // 更新
            low += cur*digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.countDigitOne(12);
    return 0;
}