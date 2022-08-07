#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> stk;
        // 加入右哨兵
        heights.push_back(0);
        for(int i = 0;i < heights.size();i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int h = heights[stk.top()];
                stk.pop();
                int width = i;
                if(!stk.empty()){
                    int top = stk.top();
                    width = i - top - 1;
                }

                res = max(res, width * h);
            }
            stk.push(i);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(heights);
    return 0;
}