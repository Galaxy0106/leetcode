#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;
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
                int area = width * h;
                ans = area > ans ? area : ans;
            }

            stk.push(i);
        }
        return ans;
    }
};

int main(){

    return 0;
}