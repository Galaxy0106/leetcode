#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void expand(string& s, string& res, int& max_len, int pos1, int pos2){        
        while (pos1 >=0 && pos2 < s.size())
        {
            if(s[pos1] == s[pos2]){
                if(pos2 - pos1 + 1 > max_len){
                    max_len = pos2 - pos1 + 1;
                    res = s.substr(pos1, pos2 - pos1 + 1);
                }
                pos1--;
                pos2++;
            }
            else
                break;  
        } 
        return;
    }


    string longestPalindrome(string s){
        int max_len = 0;
        string res;
        // 中心（奇数中心点，偶数中心点）
        for(int i = 0;i < s.size() - 1;i++){
            // 奇数扩散        
            expand(s, res, max_len, i, i);
            // 偶数扩散
            expand(s, res, max_len, i, i+1);
        }        
        expand(s, res, max_len, s.size()-1, s.size()-1);
        return res;
    }
};

int main(){
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s);
    return 0;
}