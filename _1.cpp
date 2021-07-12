#include<iostream>
#include<algorithm>
#include<vector>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> record = nums;
        sort(nums.begin(),nums.end());
        auto index1 = 0;
        auto index2 = nums.size() - 1;
        while(index1 < index2){
            int sum = nums[index1] + nums[index2];
            if(sum < target)
                ++index1;
            else if(sum > target)
                --index2;
            else
                break;
        }
        if(nums[index1] == nums[index2]){
            res = getPos(record, nums[index1]);
        }
        else{
            vector<int> res1 = getPos(record, nums[index1]);
            vector<int> res2 = getPos(record, nums[index2]);
            res.push_back(res1[0]);
            res.push_back(res2[0]);
        }
        return res;
    }

    vector<int> getPos(vector<int>& record, int num){
        vector<int> res;
        for(auto i = 0;i < record.size();i++){
            if(record[i] == num)
                res.push_back(i);
        }
        return res;
    }

};

using namespace std;

int main(){
    
    return 0;
}