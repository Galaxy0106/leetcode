#include<iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string strNum;
        int sign = 1;
        //ignore space
        int index = 0;
        while(index < s.size()){
            if(s[index] != ' ')
                break;
            ++index;
        }
        //handle sign
        if(index < s.size()){
            if(s[index] == '-'){
                sign = -1;
                ++index;
            }
            else if(s[index] == '+'){
                ++index;
            }
        }

        while(index < s.size()){
            if(s[index] < '0' || s[index] > '9')
                break;
            strNum.push_back(s[index]);
            ++index;
        }

        if(strNum.empty())
            return 0;

        long long num = 0;

        for(auto i = 0;i < strNum.size();++i){
            num = num*10 + strNum[i] - '0';
            if(sign*num > (long long)INT32_MAX)
                return INT32_MAX;
            else if(sign*num < (long long)INT32_MIN)
                return INT32_MIN;
        }
        num = sign * num;
        return num;
    }
};

int main(){
    Solution sol;
    string str = "-91283472332";
    cout << sol.myAtoi(str);
    return 0;
}