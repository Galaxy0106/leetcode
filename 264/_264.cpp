#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void initVec(vector<int>& vec, int k, int n){
        vec.push_back(1);
        int cur = 1;
        while(cur*k <= n){
            vec.push_back(cur*k);
            cur = cur*k;
        }
        return;
    }

    int nthUglyNumber(int n) {
        vector<int> vec2, vec3, vec5;
        initVec(vec2, 2, n);
        initVec(vec3, 3, n);
        initVec(vec5, 5, n);
        int i = 0, j = 0, k = 0;




    }
};

int main(){


    return 0;
}