#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)
            return true;
        bool res = true;
        for(int i = 0;i < s.size();i++){
            s[i] = tolower(s[i]);
        }

        int pos1 = 0, pos2 = s.size()-1;
        while(pos1 < pos2){
            if(!((s[pos1] >= 'a' && s[pos1] <= 'z') || (s[pos1] >= '0' && s[pos1] <= '9'))){
                pos1++;
                continue;
            }

            if(!((s[pos2] >= 'a' && s[pos2] <= 'z') || (s[pos2] >= '0' && s[pos2] <= '9'))){
                pos2--;
                continue;
            }

            if(s[pos1] != s[pos2]){
                return false;
            }

            pos1++;
            pos2--;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.isPalindrome(".,");
    return 0;
}