#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        for(int x = n, y = 1;y < m;x++, y++){
            res = res*x / y;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.uniquePaths(23, 12);
    return 0;
}