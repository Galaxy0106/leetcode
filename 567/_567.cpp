#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        bool res = false;
        unordered_map<char, int> window, needs;
        for(char& c : s1){
            needs[c]++;
        }
        // 前闭后开
        int left = 0, right = 0;
        int valid =0;
        while(right < s2.size()){
            char c = s2[right];
            right++;
            if(needs.count(c)){
                window[c]++;
                if(needs[c] == window[c]){
                    valid++;
                }
                if(valid == needs.size()){
                    res = true;
                    break;
                }
            }

            




            // else{
            //     while(right - left >= s1.size()){
            //         char d = s2[left];
            //         left++;
            //         if(needs.count(d)){
            //             if(needs[c] == window[c])
            //                 valid--;
            //             window[c]--;
            //         }
            //     }
            // }
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.checkInclusion("hello", "ooolleoooleh");
    return 0;
}
