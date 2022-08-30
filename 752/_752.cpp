#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 把第k个密码向上翻转
    string upOpFunc(string s, int k){
        char c = s[k];
        if(c == '0'){
            s[k] = '9';
        }
        else{
            s[k] = c - 1;
        }
        return s;
    }

    // 把第k个密码向下翻转
    string downOpFunc(string s, int k){
        char c = s[k];
        if(c == '9'){
            s[k] = '0';
        }
        else{
            s[k] = c + 1;
        }
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet;
        unordered_set<string> visited;
        queue<string> q;
        int step = 0;
        for(int i = 0;i < deadends.size();i++){
            deadSet.insert(deadends[i]);
        }
        q.push("0000");
        visited.insert("0000");
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i < sz;i++){
                string fStr = q.front();
                q.pop();
                if(deadSet.find(fStr) != deadSet.end()){
                    continue;
                }
                if(fStr == target){
                    return step;
                }
                for(int i = 0;i < 4;i++){
                    string upStr = upOpFunc(fStr, i);
                    string downStr = downOpFunc(fStr, i);
                    if(visited.find(upStr) == visited.end()){
                        q.push(upStr);
                        visited.insert(upStr);
                    }
                    if(visited.find(downStr) == visited.end()){
                        q.push(downStr);
                        visited.insert(downStr);
                    }  
                }
            }
            step++;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202"; 
    cout << sol.openLock(deadends, target);
    return 0;
}