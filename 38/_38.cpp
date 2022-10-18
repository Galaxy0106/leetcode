#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 0;i < n-1;i++){
            int count = 0;
            char c;
            string next_s;
            for(int j = 0;j < s.size();j++){
                if(count == 0){
                    c = s[j];
                    count++;
                }
                else{
                    if(s[j] == c){
                        count++;
                    }
                    else{
                        next_s += to_string(count);
                        next_s.push_back(c);
                        c = s[j];
                        count = 1;
                    }
                }
                if(j == s.size() - 1){
                    next_s += to_string(count);
                    next_s.push_back(c);
                    count = 0;
                }
            }
            s = next_s;
        }
        return s;
    }
};

int main(){
    Solution sol;
    cout << sol.countAndSay(4) << endl;
    return 0;
}