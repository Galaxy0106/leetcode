#include<iostream>
#include<math.h>


using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            if(res > INT32_MAX/10 || res < INT32_MIN/10)
                return 0;
            int cur = x % 10;
            x = x / 10;
            res = res * 10 + cur;
        }
        return res;
    }

};

int main(){

    return 0;
}