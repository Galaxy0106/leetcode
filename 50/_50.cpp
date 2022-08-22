#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(n == INT_MIN){
            return myPow(1/x, -(n+1))/x;
        }

        if(n < 0){
            return myPow(1/x, -n);
        }

        if(n % 2){
            return x*myPow(x, n-1);
        }
        else{
            double sub = myPow(x, n/2);
            return sub * sub;
        }
    }
};

int main(){


    return 0;
}