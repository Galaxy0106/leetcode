#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 去掉多余空格
        int index1 = 0, index2 = s.size()-1;
        while(s[index1] == ' '){index1++;}
        while(s[index2] == ' '){index2--;}
        s = s.substr(index1, index2-index1+1);
        for(int i = 0;i < s.size();i++){
            if(s[i] == ' '){
                // 找到下一个不为空格的
                i++;
                while(s[i] == ' '){
                    s.erase(s.begin() + i);
                }
                i--;
            }
        }
        reverse(s.begin(),s.end());
        index1 = 0, index2 = 0;
        while(index2 < s.size()){
            if(s[index2] == ' '){
                reverse(s.begin()+index1, s.begin()+index2);
                index1 = index2+1;
            }
            index2++;
        }
        reverse(s.begin() + index1, s.begin() + index2);
        return s;
    }
};

int main(){
    Solution sol;
    cout << sol.reverseWords("the sky is blue");

    return 0;
}