#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    void helper(int l, int r, string& temp) {
        if(l < 0 || r < 0)
            return;
        if(l == 0 && r == 0){
            res.push_back(temp);
            return;
        }
        // 放入左括号
        temp.push_back('(');
        helper(l-1, r, temp);
        temp.pop_back();

        // 放入右括号
        if(r > l){
            temp.push_back(')');
            helper(l, r-1, temp);
            temp.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        string temp;
        helper(n, n, temp);
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    for(auto& s : res){
        cout << s << "\n";
    }
    return 0;
}