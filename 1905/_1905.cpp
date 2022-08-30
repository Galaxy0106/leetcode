#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }
        if(grid[i][j] == 0)
            return;
        helper(grid, i-1, j);
        helper(grid, i+1, j);
        helper(grid, i, j-1);
        helper(grid, i, j+1);
        return;
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid2[i][j] == 1 && grid1[i][j] == 0)
                    helper(grid2, i, j);
            }
        }
        int res = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid2[i][j] == 1){
                    res++;
                    helper(grid2, i, j);
                }
            }
        }
        return res;
    }
};

int main(){

    return 0;
}