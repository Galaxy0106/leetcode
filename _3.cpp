#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(128, 0);
        auto i = 0, j = 0;
        auto res = 0;
        for(;j < s.size(); j++){
            i = max(i, vec[s[j]]);
            vec[s[j]] = j + 1;
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main(){
    string str;
    cin >> str;
    Solution sol;
    cout << sol.lengthOfLongestSubstring(str);
    return 0;
}