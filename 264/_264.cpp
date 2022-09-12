#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int min3(int a, int b, int c){
        return min(a, min(b, c));
    }

    int nthUglyNumber(int n) {
        vector<int> nums(n);
        int p = 0;
        int num2 = 1, num3 = 1, num5 = 1;
        int p1 = 0, p2 = 0, p3 = 0;
        while(p < n){
            int temp = min3(num2, num3, num5);
            nums[p++] = temp;
            if(temp == num2){
                num2 = 2 * nums[p1];
                p1++;
            }
            if(temp == num3){
                num3 = 3 * nums[p2];
                p2++;
            }
            if(temp == num5){
                num5 = 5 * nums[p3];
                p3++;
            }
        }
        return nums[n-1];
    }
};

int main(){
    Solution sol;
    cout << sol.nthUglyNumber(10);
    return 0;
}