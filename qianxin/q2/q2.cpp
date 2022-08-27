#include <bits/stdc++.h>

using namespace std;

// int getRes(vector<int>& nums){
//     int ans = INT_MIN;
//     for(int i = 0;i < nums.size();i++){
//         for(int j = i+1;j < nums.size();j++){
//             int cur = (j-i) * (nums[j] - nums[i]);
//             ans = max(ans, cur);
//         }
//     }
//     return ans;
// }


int getRes(vector<int>& height) {
    int i = 0;
    int j = height.size() - 1;
    int res = 0;
    while(i < j){
        int h = min(height[i], height[j]);
        res = max(res, (j - i)*h);
        // cout << i << " " << j << " " << res << endl;
        if(height[i] > height[j]){
            j--;
        }
        else{
            i++;
        }
    }
    return res;
}

int main(){
    vector<int> nums;
    int a;
    string s, temp;
    cin >> s;
    string str = s.substr(1, s.size() - 2);
    // cout << str << "\n";
    for(int i = 0;i < str.size();i++){
        if(str[i] == ','){
            a = stoi(temp);
            nums.push_back(a);
            temp.clear();
        }
        else{
            temp.push_back(str[i]);
        }
    }
    a = stoi(temp);
    nums.push_back(a);
    int res = getRes(nums);
    cout << res << endl;
    return 0;
}