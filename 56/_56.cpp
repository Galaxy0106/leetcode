#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        return a.front() < b.front();
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        int minL = intervals[0].front();
        int maxR = intervals[0].back();
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i].front() > maxR){
                vector<int> temp = {minL, maxR};
                res.push_back(temp);
                minL = intervals[i].front(); 
                maxR = intervals[i].back();
            }
            maxR = max(maxR, intervals[i].back());
        }
        vector<int> temp = {minL, maxR};
        res.push_back(temp);
        return res;
    }
};

using namespace std;

int main(){
    Solution sol;
    vector<vector<int>> input;
    input.push_back({1,3});
    input.push_back({2,6});
    input.push_back({8,10});
    input.push_back({15,18});
    vector<vector<int>> res = sol.merge(input);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}