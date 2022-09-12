#include <bits/stdc++.h>

using namespace std;

int res = 0;

bool isEnd(vector<bool>& visited){
    bool res = true;
    for(int i = 0;i < visited.size();i++){
        if(!visited[i]){
            res = false;
            break;
        }
    }
    return res;
}

bool isMatch(string& s, int begin, string& p){
    if(begin + p.size() > s.size())
        return false;
    int k = 0;
    while(k < p.size()){
        if(s[begin] != p[k]){
            return false;
        }
        begin++;
        k++;
    }
    return true;
}

void helper(string& s, int pos, vector<string>& strs, vector<bool>& visited) {
    if(pos == s.size() && isEnd(visited)){
        res++;
        return;
    }

    for(int i = 0;i < strs.size();i++){
        if(!visited[i] && isMatch(s, pos, strs[i])){
            visited[i] = true;
            helper(s, pos + strs[i].size(), strs, visited);
            visited[i] = false;
        }
    }

    return;
}


int main(){
    // freopen("in.txt", "r", stdin);
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    vector<int> lens(m);
    vector<string> strs(m);
    for(int i = 0;i < m;i++){
        cin >> lens[i];
    }
    for(int i = 0;i < m;i++){
        cin >> strs[i];
    }
    vector<bool> visited(m, false);
    helper(s, 0, strs, visited);
    cout << res << endl;
    return 0;
}