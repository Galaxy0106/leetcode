#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    void helper(int k, string& temp, string s, vector<bool>& visited) {
        if(k == s.size()){
            res.push_back(temp);
            return;
        }

        for(int i = 0;i < s.size();i++){
            if(!visited[i]){
                if(i > 0 && s[i] == s[i-1] && visited[i-1]){
                    break;
                }
                temp.push_back(s[i]);
                visited[i] = true;
                helper(k+1, temp, s, visited);
                temp.pop_back(); 
                visited[i] = false;
            }
        }
        return;
    }

    vector<string> permutation(string s) {
        string temp;
        int n = s.size();
        vector<bool> visited(n, false);
        sort(s.begin(), s.end());
        helper(0, temp, s, visited);
        return res;
    }
};

int main(){

    return 0;
}