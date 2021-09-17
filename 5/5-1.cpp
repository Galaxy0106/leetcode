#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s,size_t pos1, size_t pos2){
        bool flag = true;
        while(pos1 < pos2){
            if(s[pos1] == s[pos2]){
                pos1++;
                pos2--;
            }
            else{
                flag = false;
                break;
            }
        }
        return flag;
    }

    string longestPalindrome(string s) {
        string res;
        size_t max_len = 0;
        size_t pos1, pos2;
        for(size_t i = 0;i < s.size(); i++){
            for(size_t j = s.size() - 1;j >= i && j-i+1  > max_len;j--){
                if(isPalindrome(s, i, j)){
                    if(j - i + 1 > max_len){
                        max_len = j - i + 1;
                        pos1 = i;
                        pos2 = j;
                    }
                    break;
                }
            }    
        }
        res = s.substr(pos1, pos2-pos1+1);
        return res;
    }
};

int main(){
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s);
    return 0;
}