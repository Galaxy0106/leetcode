#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int k = 1;       
        int rowUp = 0, rowDown = n-1;
        int colLeft = 0, colRight = n-1;
        while(rowUp <= rowDown && colLeft <= colRight){
            if(rowUp == rowDown && colLeft == colRight){
                res[rowUp][colLeft] = k++;
                break;
            }
            // 从左到右
            for(int i = colLeft;i <= colRight;i++){
                res[rowUp][i] = k++;
            }

            // 从上到下
            for(int i = rowUp+1;i <= rowDown;i++){
                res[i][colRight] = k++;
            }
            
            // 从右到左
            for(int i = colRight-1;i >= colLeft;i--){
                res[rowDown][i] = k++;
            }

            // 从下到上
            for(int i = rowDown-1;i >= rowUp+1;i--){
                res[i][colLeft] = k++;
            }
            rowUp++, rowDown--;
            colLeft++, colRight--;
        }
        return res;
    }
};

int main(){
    Solution sol;

    return 0;
}