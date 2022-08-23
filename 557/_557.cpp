#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int index1 = 0, index2 = 0;
        for(int i = 0;i < s.size();i++){
            if(s[index2] == ' '){
                index2--;
                int m = index1, n = index2;
                while(m < n){
                    swap(s[m++], s[n--]);
                }
                index1 = index2 + 2;
                index2 = index1;
            }
            else
                index2++;
        }
        index2--;
        while(index1 < index2){
            swap(s[index1++], s[index2--]);
        }
        return s;
    }
};

int main(){
    Solution sol;
    string s = "Let's take LeetCode contest";
    cout << sol.reverseWords(s);
    return 0;
}