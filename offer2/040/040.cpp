#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangleByone(vector<int>& heights){
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

    int maximalRectangle(vector<string>& matrix) {
        int res = 0;
        if(matrix.size() == 0)
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }
                else{
                    heights[j] = heights[j] + 1;
                }
            }
            res = max(res, maximalRectangleByone(heights));
        }
        return res;
    }
};

int main(){
    vector<string> matrix = {"10100", "10111", "11111", "10010"};
    Solution sol;
    cout << sol.maximalRectangle(matrix);
    return 0;
}