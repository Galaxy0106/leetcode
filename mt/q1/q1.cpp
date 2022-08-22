#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getMaxNum(int x, int y){
    int k = min(x, y);
    int res = k;
    int extra = x + y - 2*k;
    if(extra >= k)
        return k;
    else{
        int dec = 1;
        for(int i = dec;i <= k;i++){
            if(dec == k){
                res = 0;
                break;
            }
            if(2*dec + extra >= k - dec){
                res = k - dec;
                break;
            }
        }
    }
    return res;
}

int main(){
    cout << getMaxNum(3, 7);
    return 0;
}