#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // 中心扩展
        // 奇数
        int res = 0;
        for(int i = 0;i < s.size();i++){
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                res++;
                l--,r++;
            }
        }
        // 偶数
        for(int i = 0;i < s.size() - 1;i++){
            int l = i, r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                res++;
                l--,r++;
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    cout << sol.countSubstrings("abc");
    return 0;
}