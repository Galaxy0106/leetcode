#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    int preSum[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        //  初始化
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i <= m;i++){
            preSum[i][0] = 0;
        }

        for(int j = 0;j <= n;j++){
            preSum[0][j] = 0;
        }

        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + matrix[i-1][j-1];         
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row2+1][col1] - preSum[row1][col2+1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main(){
    // vector<vector<int>> matrix = {{3,0,1,4,2}, {5,6,3,2,1}, {1,2,0,1,5}, {4,1,0,1,7}, {1,0,3,0,5}};
    vector<vector<int>> matrix = {{1,1,3},{2,2,3},{3,4,3}};
    NumMatrix *obj = new NumMatrix(matrix);
    for(int i = 0;i <= 3;i++){
        for(int j = 0;j <= 3;j++){
            cout << obj->preSum[i][j] << " ";
        }
        cout << endl;
    }
    
    // for(int i = 0;i <= matrix.size();i++){
    //     for(int j = 0;j <= matrix[i].size();j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << obj->sumRegion(1,1,2,2);
    return 0;
}