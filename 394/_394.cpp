#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        // 定义数字栈和符号栈
        stack<int> stk1;
        stack<char> stk2;
        int num;
        string ntemp;
        for(int i = 0;i < s.size();i++){
            if(s[i] >= '0' && s[i] <= '9'){
                ntemp.push_back(s[i]);
            }
            else if(s[i] == '['){
                num = stoi(ntemp);
                stk1.push(num);
                ntemp.clear();
                stk2.push('[');
            }
            else if(s[i] >= 'a' && s[i] <= 'z'){
                stk2.push(s[i]);
            }
            else{
                int top = stk1.top();
                stk1.pop();
                string temp;
                while(!stk2.empty()){
                    char c = stk2.top();
                    stk2.pop();
                    if(c == '[')
                        break;
                    temp.push_back(c);
                }
                while(top--){
                    for(int j = temp.size()-1;j >= 0;j--){
                        stk2.push(temp[j]);
                    }
                }
            }
        }
        string res;
        while(!stk2.empty()){
            char c = stk2.top();
            res.push_back(c);
            stk2.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.decodeString("abc3[cd]xyz") << endl;
    return 0;
}