#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea;
    void helper(vector<vector<int>>& grid, int i, int j, int& curArea){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n){
            maxArea = max(curArea, maxArea);
            return;
        }

        if(grid[i][j] == 0){
            maxArea = max(curArea, maxArea);
            return;
        }
        grid[i][j] = 0;
        curArea++;
        helper(grid, i-1, j, curArea);
        helper(grid, i+1, j, curArea);
        helper(grid, i, j-1 ,curArea);
        helper(grid, i, j+1, curArea);        
        return;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        maxArea = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                int curArea = 0;
                helper(grid, i, j, curArea);
                maxArea = max(curArea, maxArea);
            }
        }
        return maxArea;
    }
};

int main(){
    Solution sol;



    return 0;
}