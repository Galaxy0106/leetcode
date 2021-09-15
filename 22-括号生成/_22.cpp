#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    void dfs(vector<string>& res, string s, int ln, int rn){
        if(ln == 0 && rn == 0){
            res.push_back(s);
            return;
        }
        if(ln > 0){
            if(s.empty() || s.back() != ')'){
                ln--;
                s.push_back('(');
                dfs(res, s, ln, rn);
            }
            else
                return;
        }

        if(rn > 0){
            if(s.empty() || s.back() != '('){
                return;
            }
            else{
                rn--;
                s.push_back(')');
                dfs(res, s, ln, rn);
            }
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
    cin >> n;
    Solution s;
    vs = s.generateParenthesis(n);
    // output
    for(int i = 0;i < vs.size();i++){
        cout<< vs[i] << endl;
    }
    return 0;
}