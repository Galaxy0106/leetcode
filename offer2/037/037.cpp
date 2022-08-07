#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        stack<int> stk;
        for(int i = 0;i < asteroids.size();i++){
            if(asteroids[i] > 0){
                stk.push(asteroids[i]);
            }
            else{
                bool flag = true;
                while(!stk.empty()){
                    int top = stk.top();
                    if(top > abs(asteroids[i])){
                        // 向左的小行星爆炸
                        flag = false;
                        break;
                    }
                    else if(top == abs(asteroids[i])){
                        // 两个小行星一起爆炸
                        flag = false;
                        stk.pop();
                        break;
                    }
                    else{
                        stk.pop();
                    }
                }
                if(flag == true){
                    res.push_back(asteroids[i]);
                }
            }
        }
        int n = res.size();        
        while(!stk.empty()){
            int top = stk.top();
            res.insert(res.begin() + n, top);
            stk.pop();
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> asters = {-2, -1, 1, 2};
    vector<int> res = sol.asteroidCollision(asters);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}