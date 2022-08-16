#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, needs;
        for(int i = 0;i < t.size();i++){
            needs[t[i]]++;
        }
        int valid = 0;
        // 前闭后开的区间
        int left = 0, right = 0;
        int start = 0, len = INT_MAX;
        while(right < s.size()){
            // 即将移入窗口的字符
            char c = s[right];
            // 扩大窗口
            right++;
            if(needs.count(c)){
                window[c]++;
                if(window[c] == needs[c])
                    valid++;
            }
            // 判断左侧窗口是否要收缩
            while(valid == needs.size()){
                if(right - left < len){
                    start = left;
                    len = right - left;
                }

                // 即将移出窗口的字符
                char d = s[left];
                // 缩小窗口
                left++;
                // 进行窗口内数据的一系列更新
                if(needs.count(d)){
                    if(window[d] == needs[d]){
                        valid--;
                    }
                    window[d]--;
                }

            }
        }
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};

int main(){
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}