#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        bool res = true;
        int index = 0;
        stack<int> stk;
        for(int i = 0;i < pushed.size();i++){
            stk.push(pushed[i]);
            while(!stk.empty()){
                int top = stk.top();
                if(popped[index] == top){
                    stk.pop();
                    index++;
                }
                else
                    break;
            }
        }
        return stk.empty();
    }
};

int main(){
    Solution sol;
    vector<int> pushed = {1,2,3,4,5};
    vector<int> poped = {4,3,5,1,2};
    cout << sol.validateStackSequences(pushed, poped);
    return 0;
}