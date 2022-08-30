#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    struct cmp{
        bool operator() (pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;    
        priority_queue<pair<int,int>, vector< pair<int,int> >, cmp> pq;
        vector<int> res;
        // 遍历记录次数
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]]++;
        }
        // 维护一个小根堆
        for(auto iter = mp.begin();iter != mp.end();iter++){
            if(pq.size() < k){
                pq.push({iter->first, iter->second});
            }
            else{
                if(iter->second > pq.top().second){
                    pq.pop();
                    pq.push({iter->first, iter->second});
                }
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> res;
    int k = 2;
    res = sol.topKFrequent(nums, k);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}