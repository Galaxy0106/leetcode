#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> nums;
    int a;
    while(cin >> a){
        nums.push_back(a);
    }
    // 定义dp数组
    int n = nums.size();
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        if(i == 1)
            dp[i] = nums[0];
        dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    }
    cout << dp[n] << endl;
    return 0;
}