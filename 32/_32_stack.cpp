#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int res = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '('){
                stk.push(i);
            }
            else{
                stk.pop();
                if(!stk.empty()){
                    int temp = i - stk.top();
                    res = max(res, temp);
                }
                else{
                    stk.push(i);
                }
            }
        }
        return res;
    }
};

// int main(){
//     Solution sol;
//     cout << sol.longestValidParentheses(")()())");
//     return 0;
// }