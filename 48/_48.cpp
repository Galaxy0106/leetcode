#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<int> >& matrix){
    for(size_t i = 0;i < matrix.size();i++){
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;    
}


class Solution {
public:
    void swap(vector<vector<int>>& matrix, size_t x1, size_t y1, size_t x2, size_t y2){
        int temp = matrix[x1][y1];
        matrix[x1][y1] = matrix[x2][y2];
        matrix[x2][y2] = temp;
    }

    void rotate(vector<vector<int>>& matrix) {
        size_t size = matrix.size();
        // 矩阵的每一圈
        for(size_t k = 0;k < (size+1)/2;k++){
            // 每一圈的四个元素
            for(size_t m = 0;m < (size - 2*k -1);m++){
                //具体的四个元素
                swap(matrix, k, k+m, k+m, size-k-1);
                print(matrix); 

                swap(matrix, size-k-1, size-k-1-m, size-k-1-m, k);
                print(matrix); 
                
                swap(matrix, k, k+m, size-k-1, size-k-1-m);
                print(matrix); 
            }
        } 
        return;
    }
};

int main(){
    Solution s;
    vector<vector<int> > matrix= {{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};
    print(matrix);
    s.rotate(matrix);
    // print
    print(matrix);
    return 0;
}