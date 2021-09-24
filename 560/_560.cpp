#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // pre表示当前pre[i]的值
        int pre = 0;
        int count = 0;
        // key 为和， value 为次数
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(auto& num: nums){
            pre += num;
            // 找到key
            if(mp.find(pre - k) != mp.end()){
                count += mp[pre-k];
            }
            mp[pre]++;
        }
        return count;
    }
};

using namespace std;

int main(){


    return 0;
}