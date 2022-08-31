#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> win;
        unordered_map<char, int> need;
        int valid = 0;
        for(int i = 0;i < p.size();i++){
            need[p[i]]++;
        }
        int left = 0, right = 0;
        while(right < s.size()){
            // 增大窗口
            char c = s[right];
            right++;
            if(need.count(c)){
                win[c]++;
                if(win[c] == need[c])
                    valid++;
            }

            // 缩小窗口
            while(right - left > p.size()){
                char d = s[left];
                left++;
                if(need.count(d)){
                    if(win[d] == need[d])
                        valid--;
                    win[d]--;
                }
            }
            if(valid == need.size()){
                res.push_back(left);
            }
        }
        return res;
    }
};


int main(){
    Solution sol;
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = sol.findAnagrams(s, p);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}