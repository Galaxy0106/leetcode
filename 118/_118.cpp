#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp;
        temp.push_back(1);
        res.push_back(temp);
        for(int i = 1;i < numRows;i++){
            temp.clear();
            for(int j = 0;j <= i;j++){
                int left = 0, right = 0;
                if(j-1 >= 0)
                    left = res.back()[j-1];
                if(j < i)
                    right = res.back()[j];
                temp.push_back(left + right);
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> res = sol.generate(5);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
