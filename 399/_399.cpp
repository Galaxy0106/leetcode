#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for(int i = 0;i < queries.size();i++){
            
        }

    }
};

int main(){
    Solution sol;
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    vector<double> res = sol.calcEquation(equations, values, queries);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}