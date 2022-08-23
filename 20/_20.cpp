#include<iostream>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto i = 0;i < s.size();i++){
            if(stk.empty()){
                stk.push(s[i]);
            }
            else{
                if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                    stk.push(s[i]);
                else{
                    if(s[i] == ')'){
                        if(stk.top() == '(')
                            stk.pop();
                        else
                            return false;
                    }
                    else if(s[i] == ']'){
                        if(stk.top() == '[')
                            stk.pop();
                        else
                            return false;                        
                    }
                    else{
                        if(stk.top() == '{')
                            stk.pop();
                        else
                            return false;                          
                    }
                }
            }
        }
        if (stk.empty())
            return true;
        else
            return false;
    }
};

int main(){
    Solution sol;
    string s = "()[]{}";
    bool result = sol.isValid(s);
    if(result)
        cout << "True";
    else
        cout << "False";
    return 0;
}