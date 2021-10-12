#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;
        else{
            int origin = x;
            int y;
            long long revx = 0;
            while(x){
                y = x%10;
                x = x/10;
                revx = revx*10 + y;
            }
            if(revx == origin)
                return true;
            else   
                return false;

        }
    }
};

int main(){
    Solution sol;
    if(sol.isPalindrome(121))
        cout << "True";
    else
        cout << "False";

}