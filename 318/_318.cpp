#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judge(vector<vector<int>>& rds, int x, int y){
        bool res = true;
        for(int i = 0;i < 26;i++){
            if(rds[x][i] == 1 && rds[y][i] == 1){
                res = false;
                break;
            }
        }
        return res;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> rds(n, vector<int>(26, 0)); 
        // 初始化hash table
        for(int i = 0;i < n;i++){
            for(int j = 0;j < words[i].size();j++){
                int pos = words[i][j] - 'a';
                rds[i][pos] = 1;
            }
        }
        int res = 0;

        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(judge(rds, i, j)){
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << sol.maxProduct(words);
    return 0;
}