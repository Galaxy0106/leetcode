#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // void printBits(int n){
    //     string res;
    //     while(n){
    //         int k = n%2;
    //         res.push_back(k + '0');
    //         n = n/2; 
    //     }
    //     string temp(32 - res.size(), '0');
    //     res += temp;
    //     reverse(res.begin(), res.end());
    //     cout << res << "\n";
    // }

    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> rd(n, 0);

        // 初始化hash table
        for(int i = 0;i < n;i++){
            for(int j = 0;j < words[i].size();j++){
                int offset = words[i][j] - 'a';
                rd[i] = rd[i] | (1 << offset);
            }
        }

        // 打印二进制
        // for(int i = 0;i < n;i++){
        //     printBits(rd[i]);
        // }


        int res = 0;

        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(!(rd[i] & rd[j])){
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << sol.maxProduct(words);
    return 0;
}