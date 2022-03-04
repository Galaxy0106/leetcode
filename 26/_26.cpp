#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        int index = 1;
        int cur = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] != cur){
                //交换元素
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                cur = temp;
                index++;
            }            
        }
        return index;
    }
};

int main(){
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    int num = sol.removeDuplicates(v);
    cout<<num<<"\n";
    for(int i = 0;i < num;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}