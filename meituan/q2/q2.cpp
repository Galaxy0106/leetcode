#include <bits/stdc++.h>

using namespace std;


int findPos(vector<int>& arr, int val){
    int pos = -1;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == val){
            pos = i;
            break;
        }
    }
    return pos;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> opVec(m);
    vector<int> arr(n);
    for(int i = 0;i < m;i++){
        cin >> opVec[i];
    }
    for(int i = 1;i <= n;i++){
        arr[i-1] = i;
    }

    for(int i = 0;i < m;i++){
        // 找到位置
        int pos = findPos(arr, opVec[i]);
        // 删除
        arr.erase(arr.begin() + pos);
        // 插入
        arr.insert(arr.begin(), opVec[i]);
    }
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}