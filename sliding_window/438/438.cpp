#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        vector<int> ans;
        for(auto c: p){
            need[c]++;
        }
        int valid = 0;
        int left = 0, right = 0;
        while(right < s.size()){
            char c1 = s[right];
            right++;
            if(need.count(c1)){
                window[c1]++;
                if(window[c1] == need[c1])
                    valid++;
            }            
            if(valid == need.size()){
                ans.push_back(left);
            }
            if(right >= p.size()){
                char c2 = s[left];
                left++;
                if(need.count(c2)){
                    window[c2]--;
                    if(window[c2] == need[c2] - 1)
                        valid--;
                }
            } 
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> ans;
    string s = "cbaebabacd", p = "abc";
    ans = sol.findAnagrams(s, p);
    for(auto a : ans){
        cout << a << " ";
    }
    return 0;
}