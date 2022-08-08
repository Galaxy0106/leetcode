#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 哈希表
        int nums[1001] = {0};
        for(int i = 0;i < arr1.size();i++){
            nums[arr1[i]]++;
        }
        int index = 0;
        for(int i = 0;i < arr2.size();i++){
            while(nums[arr2[i]]--){
                arr1[index++] = arr2[i];
            }
        }

        for(int i = 0;i <= 1000;i++){
            while(nums[i] > 0){
                arr1[index++] = i;
                nums[i]--;
            }
        }
        return arr1;
    }
};

int main(){
    Solution sol;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> res = sol.relativeSortArray(arr1, arr2);
    for(int i = 0;i < res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}