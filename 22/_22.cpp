#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, string s, int ln, int rn){
        if(ln == 0 && rn == 0){
            res.push_back(s);
            return;
        }
        if(ln == rn){
        // 只能用左括号
            s.push_back('(');
            dfs(res, s, ln-1, rn);
        }
        else if(ln < rn){
        // 左括号和右括号都能用
            if(ln > 0){
                s.push_back('(');
                dfs(res, s, ln-1, rn);
                s.pop_back();
            }
            s.push_back(')');
            dfs(res, s, ln, rn-1);
            s.pop_back();    
        }       
        return;
    }


    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s; 
        dfs(res, s, n, n);
        return res;
    }
};


int main(){
    int  n;
    vector<string> vs;
    // cin >> n;
    Solution s;
    vs = s.generateParenthesis(3);
    // output
    for(int i = 0;i < vs.size();i++){
        cout<< vs[i] << endl;
    }
    return 0;
}