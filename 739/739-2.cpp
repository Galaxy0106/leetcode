#include<bits/stdc++.h>

using namespace std;


// 单调栈解法
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> stk;
        for(int i = temperatures.size() - 1;i >= 0;i--){
            int curTemp = temperatures[i];
            int res;
            while(!stk.empty() && temperatures[stk.top()] <= curTemp){
                stk.pop();
            }
            res = stk.empty()? 0 : stk.top() - i;
            stk.push(i);
            ans[i] = res;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> input = {73,74,75,71,69,72,76,73};
    vector<int> res = sol.dailyTemperatures(input);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }

    return 0;
}