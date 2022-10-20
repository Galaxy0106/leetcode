#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int posx = 0, posy = n-1;
        while(posx < m && posy >= 0){
            int k = matrix[posx][posy];
            if(k < target){
                posx++;
            }
            else if(k > target){
                posy--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << sol.searchMatrix(matrix, 13) << endl;
    return 0;
}