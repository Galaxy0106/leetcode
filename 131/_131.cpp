#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string& s, int start, int end){
        if(start > end)
            return false;
        int l = start, r = end;
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }


    void helper(int k, vector<string>& temp, string s){
        if(k == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i = k;i < s.size();i++){
            if(isPalindrome(s, k, i)){
                temp.push_back(s.substr(k, i-k+1));
                helper(i+1, temp, s);
                temp.pop_back();
            }
        }
        return;
    }


    vector<vector<string>> partition(string s) {
        vector<string> temp;
        helper(0, temp, s);
        return res;
    }
};

int main(){

    return 0;
}