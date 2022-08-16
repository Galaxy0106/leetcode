#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rowUp = 0, rowDown = matrix.size()-1;
        int colLeft = 0, colRight = matrix[0].size()-1; 

        while(rowUp <= rowDown && colLeft <= colRight){
            // 从左到右
            for(int i = colLeft;i <= colRight;i++){
                res.push_back(matrix[rowUp][i]);
            }

            // 从上到下
            for(int i = rowUp+1;i <= rowDown;i++){
                res.push_back(matrix[i][colRight]);
            }

            // 从右到左
            if(rowDown > rowUp)
                for(int i = colRight-1;i >= colLeft;i--){
                    res.push_back(matrix[rowDown][i]);
                }
            
            // 从下到上
            if(colRight > colLeft)
                for(int i = rowDown-1;i >= rowUp+1;i--){
                    res.push_back(matrix[i][colLeft]);
                }
            rowUp++, rowDown--;
            colLeft++, colRight--;
        }
        return res;
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    Solution sol;
    vector<int> res = sol.spiralOrder(matrix);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}