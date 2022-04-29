#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map_strs;
        unordered_map<string, vector<string>> ::iterator iter;
        for(int i = 0;i < strs.size();i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            iter = map_strs.find(s);
            if(iter == map_strs.end()){
                // not find
                vector<string> vs;
                vs.push_back(strs[i]);
                map_strs.insert(pair<string, vector<string>> (s, vs));
            }
            else{
                // find
                map_strs[s].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for(iter = map_strs.begin();iter != map_strs.end();iter++){
            ans.push_back(iter->second);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    freopen("input.txt", "r", stdin);
    string s;
    vector<string> strs;
    vector<vector<string>> res;
    while(cin >> s)
        strs.push_back(s);
    res = sol.groupAnagrams(strs);
    // cout << res.size();

    // output
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}