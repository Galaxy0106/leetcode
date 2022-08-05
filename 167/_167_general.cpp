#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int l = 0, r = numbers.size() - 1;
        while(l < r){
            if(numbers[l] + numbers[r] > target){
                r--;
                // int temp = numbers[r];
                // while(l < r && numbers[--r] == temp){}
            }
            else if(numbers[l] + numbers[r] < target){
                l++;
                // int temp = numbers[l];
                // while(l < r && numbers[++l] == temp){}
            }
            else{
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
                // res.push_back(ans);
                // int temp1 = nums[l], temp2 = nums[r];
                // while(l < r && nums[++l] == temp1){}
                // while(l < r && nums[--r] == temp2){}
            }
        }
        return ans;
    }
};

int main(){

    return 0;
}