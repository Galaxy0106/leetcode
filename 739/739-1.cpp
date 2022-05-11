#include<bits/stdc++.h>

using namespace std;


// 暴力解法
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        int index1 = -1;
        for(int i = 0;i < temperatures.size();i++){
            int curTemp = temperatures[i];
            // find higher temperature
            int res = 0;
            bool flag = (index1 != -1 && curTemp >= temperatures[index1] && ans[index1] == 0);
            if(!flag){          
                for(int j = i+1;j < temperatures.size();j++){
                    if(temperatures[j] > curTemp){
                        res = j - i;
                        break;
                    }
                }
            }
            if(res == 0){
                index1 = i;
            }
            ans.push_back(res);
        }
        return ans;
    }
};

// int main(){
//     Solution sol;
//     vector<int> input = {73,74,75,71,69,72,76,73};
//     vector<int> res = sol.dailyTemperatures(input);
//     for(int i = 0;i < res.size();i++){
//         cout << res[i] << " ";
//     }

//     return 0;
// }