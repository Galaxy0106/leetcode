#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i = 0;i < tokens.size();i++){
            string s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                if(s == "+")
                    stk.push(left + right);
                else if(s == "-")
                    stk.push(left - right);
                else if(s == "*")
                    stk.push(left * right);
                else
                    stk.push(left / right);
            }
            else{
                stringstream ss;
                int temp;
                ss << s;
                ss >> temp;
                stk.push(temp);
            }
        }
        return stk.top();
    }
};

int main(){
    Solution sol;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << sol.evalRPN(tokens);
    return 0;
}