#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> win;
        unordered_map<char, int> need;
        int valid = 0;
        for(int i = 0;i < s1.size();i++){
            need[s1[i]]++;
        }
        int left = 0, right = 0;
        while(right < s2.size()){
            // 增大窗口
            char c = s2[right];
            right++;
            if(need.count(c)){
                win[c]++;
                if(win[c] == need[c]){
                    valid++;
                }
            }
            // 收缩窗口
            while(right - left > s1.size()){
                char d = s2[left];
                left++;
                // 窗口内的数据更新
                if(need.count(d)){
                    if(win[d] == need[d]){
                        valid--;
                    }
                    win[d]--;
                }
            }
            if(valid == need.size())
                return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout << sol.checkInclusion("hello", "ooolleoooleh");
    return 0;
}
