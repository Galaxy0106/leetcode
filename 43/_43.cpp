#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string subMultiply(string num1, char c) {
        string res;
        int carry = 0;
        for(int i = num1.size() - 1;i >= 0;i--){
            int k = (num1[i] - '0') * (c - '0') + carry;
            carry = k/10;
            int cur = k%10;
            res.push_back(cur + '0');
        }
        if(carry){
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string add(string num1, string num2){
        string res;
        int m = num1.size();
        int n = num2.size();
        if(m < n){
            string temp(n-m, '0');
            num1 = temp + num1;
        }

        if(m > n){
            string temp(m-n, '0');
            num2 = temp + num2;
        }
        int bound = max(m, n);
        int carry = 0;
        for(int i = bound-1;i >= 0;i--){
            int k = num1[i] - '0' + num2[i] - '0' + carry;
            carry = k/10;
            int cur = k%10;
            res.push_back(cur + '0');
        }
        if(carry){
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        // 子乘法
        string res;
        for(int i = n-1;i >= 0;i--){
            string cur = subMultiply(num1, num2[i]);
            string temp(n-1-i, '0');
            cur += temp;
            res = add(res, cur);
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.multiply("123", "456") << endl;
    return 0;
}