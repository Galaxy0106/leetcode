#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int t){
        int sum = 0;
        while(t){
            sum += t%10;
            t = t/10;
        }
        return sum;
    }

    bool isSatisfied(int x, int y, int k){
        int sum = getSum(x) + getSum(y);
        return sum > k ? false : true;
    }

    int count(int x, int y, int k, vector<vector<bool>>& visited){
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
        // cout << x << " " << y << "\n";
        if(isSatisfied(x, y, k)){
            visited[x][y] = true;
            int res = 1;
            for(const auto& dir : dirs){
                int newx = x + dir.first;
                int newy = y + dir.second;
                if(newx >= 0 && newx < visited.size() && newy >= 0 && newy < visited[0].size()){
                    if(!visited[newx][newy]){
                        res += count(newx, newy, k, visited);
                    }
                }
            }
            // visited[x][y] = false;
            return res;
        }
        return 0;
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return count(0, 0, k, visited);
    }
};

int main(){
    Solution sol;
    cout << sol.movingCount(3, 2, 17);
    return 0;
}