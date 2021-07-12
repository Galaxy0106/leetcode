#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        auto len = s.size();
        string res;
        auto i = 0;
        for(auto i = 0;i < numRows;i++){
            auto delta1 = 2*(numRows - i - 1);
            auto delta2 = 2*i;
            vector<int> delta;
            delta.push_back(delta1);
            delta.push_back(delta2);
            auto j = i;
            int index = 0;
            if(delta1 == 0){
                while(j < s.size()){
                    res.push_back(s[j]);
                    // cout<< s[j] << endl;
                    j += delta2;
                }
            }
            else if(delta2 == 0){
                while(j < s.size()){
                    res.push_back(s[j]);
                    cout<< s[j] << endl;
                    j += delta1;
                }                
            }
            else{
                while(j < s.size()){
                    res.push_back(s[j]);
                    cout<< s[j] << endl;
                    j += delta[index];
                    index = (index + 1)%2;
                }
            }
        }
        return res;
    }
};

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution sol;
    cout << sol.convert(s, numRows);
    return 0;
}