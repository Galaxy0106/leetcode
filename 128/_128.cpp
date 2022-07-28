#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> nums_set;
        for(auto num : nums){
            nums_set.insert(num);
        }

        for(auto iter = nums_set.begin();iter != nums_set.end();iter++){
            if(nums_set.count(*iter - 1))
                continue;
            int x = *iter;
            while(nums_set.count(x)){
                x++;
            }
            res = max(res, x - *iter);
        }
        return res;
    }
};


int main(){

    return 0;
}