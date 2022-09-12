#include <bits/stdc++.h>

using namespace std;


bool isMatch(string& s1, string& s2, int begin, int end){
    bool res = true;
    int k = 0;
    for(int i = begin;i <= end;i++){
        if(!(s1[i] == s2[k] || s2[k] == '*')){
            res = false;
            break;
        }
        k++;
    }
    return res;
}

int main(){
    int n, m;
    int ans = 0;
    string s1, s2;
    cin >> n >> m;
    cin >> s1;
    cin >> s2;
    int len = s2.size();
    for(int i = 0;i < s1.size();i++){
        if(isMatch(s1, s2, i, i+len-1)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}