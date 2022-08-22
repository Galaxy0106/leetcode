#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        // hash table 记录次数
        unordered_map<char, int> mp_count;
        bool inStack[256] = {false};
        stack<char> stk;
        for(int i = 0;i < s.size();i++){
            mp_count[s[i]]++;
        }
        
        for(int i = 0;i < s.size();i++){
            char c = s[i];
            mp_count[c]--;
            if(inStack[c])
                continue;
            while(!stk.empty()){
                int top = stk.top();
                if(top > c && mp_count[top] > 0){
                    stk.pop();
                    inStack[top] = false;
                }
                else
                    break;
            }
            stk.push(c);
            inStack[c] = true;
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(){
    Solution sol;
    string s = "bbcaac";
    cout << sol.removeDuplicateLetters(s);
    return 0;
}