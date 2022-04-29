#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is_match(int map_letter[], string s, size_t size){
        if(s.empty()){
            for(int i = 0;i < 26; i++){
                if(map_letter[i] != 0 )
                    return false;
            }
            return true;
        }

        if(s.size() != size){
            return false;
        }

        for(int i = 0;i < size;i++){
            int index = s[i] - 'a';
            if(map_letter[index] > 0){
                map_letter[index]--;
            }
            else{
                return false;
            }  
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 遍历字符串数组的flag
        bool vis[10000];
        memset(vis, false, 10000);
        vector<vector<string>> res;
        for(int i = 0;i < strs.size();i++){
            int map_letter[26] = {0};
            vector<string> temp;
            if(!vis[i]){
                temp.push_back(strs[i]);
                for(int j = 0;j < strs[i].size();j++){
                    int index = strs[i][j] - 'a';
                    map_letter[index]++;       
                }

                // search
                for(int j = i+1;j < strs.size();j++){
                    // is_match
                    int copy[26];
                    memcpy(copy, map_letter, 26*sizeof(int));
                    if(is_match(copy, strs[j], temp.size())){
                        temp.push_back(strs[j]);
                        vis[j] = true;
                    }
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};

// int main(){
//     Solution sol;
//     freopen("input.txt", "r", stdin);
//     string s;
//     vector<string> strs;
//     vector<vector<string>> res;
//     while(cin >> s)
//         strs.push_back(s);
//     res = sol.groupAnagrams(strs);
//     // cout << res.size();
//     // output
//     for(int i = 0;i < res.size();i++){
//         for(int j = 0;j < res[i].size();j++){
//             cout << res[i][j] << " ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }