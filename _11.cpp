#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            res = max(res, (j - i)*h);
            cout << i << " " << j << " " << res << endl;
            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> v = {5,5,6,2,5,4,8,6,5};
    Solution s;
    int res = s.maxArea(v);
    cout << res;
    return 0;
}