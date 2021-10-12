#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int first = 0;
        int second = 1;
        int res = 0;
        for(int i = 1;i <= n; i++){
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
};

int main(){

    return 0;
}