#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int m = a.size();
        int n = b.size();
        int k = max(m, n);
        // 填充0
        if(m < n){
            string temp(n-m, '0');
            a = temp + a;
        }
        if(m > n){
            string temp(m-n, '0');
            b = temp + b;
        }

        int incre = 0;

        for(int i = 1; i <= max(m, n);i++){
            int sum = a[k-i] - '0' + b[k-i] - '0' + incre;
            int cur = sum % 2;
            incre = sum / 2;
            res.insert(res.begin(), cur + '0');
        }
        if(incre)
            res.insert(res.begin(), '1');
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.addBinary("1010", "101");
    return 0;
}