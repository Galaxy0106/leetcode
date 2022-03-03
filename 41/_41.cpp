#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(int i = 0;i < nums.size();i++){
            if( nums[i] <= 0 || nums[i] > N){
                nums[i] = N+1;
            }
        }

        for(int i = 0;i < N;i++){
            int temp = abs(nums[i]);
            if(temp != N+1){
                if(nums[temp-1] > 0){
                    nums[temp-1] = -nums[temp-1];
                }
            }
        }
        int res = N + 1;
        for(int i = 0;i < N;i++){
            if(nums[i] > 0){
                res = i+1;
                break;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> a = {3,4,-1,1}; 
    int res = s.firstMissingPositive(a);
    cout << res;
    return 0;
}