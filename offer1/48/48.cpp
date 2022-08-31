#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = -1;
        int left = 0, right = 0;
        unordered_map<char, int> win;
        while(right < s.size()){
            // 窗口增大
            char c = s[right];
            win[c]++;
            right++;
            // cout << "[" << left << "," << right << ")" << endl; 
            // 窗口缩小
            while(win[c] > 1){
                char d = s[left];
                left++;
                win[d]--;
            }
            // cout << "[" << left << "," << right << ")" << endl; 
            res = max(res, right - left);
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb");
    return 0;
}