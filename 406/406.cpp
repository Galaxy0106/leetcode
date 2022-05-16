#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](vector<int>& a,vector<int>& b){
            if(a[0] != b[0])
                return a[0] > b[0];
            else
                return a[1] < b[1];
        };

        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> ans;
        for(vector<int> p : people){
            // insert
            ans.insert(ans.begin() + p[1], p);
        }
        return ans;
    }
};

int main(){

    return 0;
}