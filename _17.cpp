#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<int> nums;
        for(auto i = 0;i < digits.size();i++){
            nums.push_back(digits[i] - '0');
        }

        dfs("", nums, res);
        return res;
    }

    void dfs(string s, vector<int> nums, vector<string>& res){
        if(s.size() == nums.size()){
            res.push_back(s);
            return;
        }
        int num = nums[s.size()];
        string numStr = getString(num);
        for(auto i = 0;i < numStr.size();i++){
            char c = numStr[i];
            s.push_back(c);
            dfs(s, nums, res);
            s.pop_back();
        }
        return;
    }

    string getString(int num){
        string res;
        if(num >= 2 && num <= 6){
            for(auto i = 0;i < 3;i++){
                char c = (num - 2)*3 + 'a' + i;
                res.push_back(c);
            }
        }
        else if(num == 7){
            res.push_back('p');
            res.push_back('q');
            res.push_back('r');
            res.push_back('s');
        }
        else if(num == 8){
            res.push_back('t');
            res.push_back('u');
            res.push_back('v');
        }
        else{
            res.push_back('w');
            res.push_back('x');
            res.push_back('y');
            res.push_back('z');
        }
        return res;
    }
};

int main(){
    Solution sol;
    string input = "235";
    vector<string> vec;
    vec = sol.letterCombinations(input);
    //output
    for (auto i = 0; i < vec.size(); i++)
    {
        cout << vec[i] <<endl;
    }

    return 0;
}