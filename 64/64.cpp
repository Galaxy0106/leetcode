#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>&grid, int x, int y, int sum){
        if(x == grid[0].size() && y == grid.size()){
            ans = max(ans, sum);
            return;
        }
        if(x < grid[0].size())
            dfs(grid, x+1, y, sum + grid[y][x]);
        else
            return;
        if(y < grid.size())
            dfs(grid, x, y+1, sum + grid[y][x]);
        else
            return;
    }

    int minPathSum(vector<vector<int>>& grid) {
        dfs(grid, 0, 0, 0);
        return ans; 
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    sol.minPathSum(grid);
    cout << sol.ans;
    return 0;
}