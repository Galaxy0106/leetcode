#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3){
            return res;
        }
        //sort
        sort(nums.begin(), nums.end());
        int i = nums.size() - 1;
        while(i > 1){
            int num = -nums[i];
            int left = 0;
            int right = i - 1;
            int upper = nums[right] * 2;
            int lower = nums[left] * 2;
            if(num < lower || num > upper){
                --i;
                continue;
            }
            //Two indexes
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum < num){
                    ++left;
                }
                else if(sum > num){
                    --right;
                }
                else{
                    vector<int> v;
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    v.push_back(-num);
                    res.push_back(v);
                    int cur_left = nums[left];
                    int cur_right = nums[right];
                    while (left < right && nums[++left] == cur_left);
                    while (left < right && nums[--right] == cur_right);
                }
            }
            while (i > 1 && nums[--i] == -num);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v = {0,0,0};
    vector<vector<int>> res;
    res = s.threeSum(v);
    for(int i = 0;i < res.size();++i){
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<< res[i][j] << " ";
        }
        cout<<"\n";
    }
    return 0;
}