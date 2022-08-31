#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int m = nums1.size();
        int n = nums2.size();
        auto cmp = [&](pair<int, int>& lhs, pair<int, int>& rhs){
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> pq(cmp);
        for(int i = 0;i < min(m, k);i++){
            pq.push({i, 0});
        }

        while(k-- && !pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            ans.push_back({nums1[x], nums2[y]});
            if(y + 1 < n){
                pq.push({x, y+1});
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;
    vector<vector<int>> ans = sol.kSmallestPairs(nums1, nums2, k);
    for(int i = 0;i < ans.size();i++){
        for(int j = 0;j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}