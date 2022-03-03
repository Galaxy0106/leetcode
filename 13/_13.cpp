#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int res = 0;
        char cur, next;
        if(s.size() == 1){
            res = symbolValues.at(s[0]);
            return res;
        }

        for(int i = 0;i < s.size();i++){
            cur = s[i];
            next = s[i+1];
            if(symbolValues[cur] < symbolValues[next]){
                res += symbolValues[next] - symbolValues[cur];
                i++;
            }    
            else{
                res += symbolValues[cur];
            }
        }  
        return res;
    }
};


int main(){
    Solution sol;
    string s = "MCMXCIV";
    cout << sol.romanToInt(s);
    return 0;
}