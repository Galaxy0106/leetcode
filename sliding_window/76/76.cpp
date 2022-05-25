#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char c : t){
            need[c]++;
        }
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;
        int valid = 0;
        while(right < s.size()){
            // c 是将移入窗口的字符
            char c = s[right];
            right++;
            // 更新数据
            if(need.count(c)){
                window[c]++;
                if(window[c] == need[c]){
                    valid++;
                }
            }

            // 判断 左侧窗口是否要收缩
            while(valid == need.size()){
                // 更新
                if(right - left < len){
                    start = left;
                    len = right - left;
                }
                // 将要移出窗口的数据
                char c = s[left];
                left++;
                // 更新数据
                if(need.count(c)){
                    window[c]--;
                    if(window[c] < need[c]){
                        valid--;
                    }
                }
            }
        }
        return len == INT32_MAX ? "" : s.substr(start, len);
    }
};

int main(){
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    cout << sol.minWindow(s, t);
    return 0;
}
