#include<bits/stdc++.h>

using namespace std;

// 单调栈解法
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        for(int i = 0;i < height.size();i++){
            while(!stk.empty() && height[i] > height[stk.top()]){
                int top = stk.top();
                stk.pop();
                if(stk.empty()){
                    break;
                }
                int left = stk.top();
                int width = i - left - 1;
                int h = min(height[left], height[i]) - height[top];
                ans += width * h;
            }
            stk.push(i);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> input = {4,2,3};
    int res = sol.trap(input);
    cout << res << endl;
    return 0;
}