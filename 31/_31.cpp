#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int findNextNum(vector<int>& nums, int index){
        int nextNum = nums[index];
        int pos = nums.size();
        for(int i = index + 1;i < nums.size();i++){
            if(nums[i] > nums[index]){
                if(nextNum == nums[index]){
                    nextNum = nums[i];
                    pos = i;
                }
                else{
                    if(nums[i] < nextNum){
                        nextNum = nums[i];
                        pos = i;
                    }
                }
            }
        }
        return pos;
    }

    void nextPermutation(vector<int>& nums) {
        int index1, index2;
        if(nums.size() == 1){
            return;
        }

        for(index1 = nums.size() - 2;index1 >= 0;index1--){
            index2 = findNextNum(nums, index1);
            if(index2 != nums.size()){
                swap(nums[index1], nums[index2]);
                break;
            }            
        }
        sort(nums.begin() + index1 + 1, nums.end());
        return;
    }
};


int main(){
    Solution s;
    vector<int> nums = {2, 3, 1};
    s.nextPermutation(nums);
    for(int i = 0;i < nums.size();i++){
        cout << nums[i] << " ";
    }

    return 0;
}