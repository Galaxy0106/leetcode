#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> res;
    bool isValid(string& s, int begin, int end){
        if(s.empty())
            return false;
        string temp = s.substr(begin, end - begin + 1);
        if(temp.size() > 1 && temp[0] == '0')
            return false;
        int subIP;
        stringstream ss;
        ss << temp;
        ss >> subIP;
        return subIP >= 0 && subIP <= 255;
    }

    void helper(int k, vector<string>& temp, string s){
        if(k == s.size() && temp.size() == 4){
            string subRes = temp[0] + "." + temp[1] + "." + temp[2] + "." + temp[3];
            res.push_back(subRes);
            return;
        }
        if(temp.size() == 4)
            return;

        for(int i = k;i < s.size();i++){
            if(isValid(s, k, i)){
                string sub = s.substr(k, i-k+1);
                temp.push_back(sub);
                helper(i+1, temp, s);
                temp.pop_back();
            }
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> temp;
        helper(0, temp, s);
        return res;
    }
};

int main(){
    Solution sol;
    string s = "11111111111111111111111111111111";
    vector<string> ans = sol.restoreIpAddresses(s);
    for(auto& s : ans){
        cout << s << "\n";
    }
    return 0;
}