#include <bits/stdc++.h>

using namespace std;

int res = INT_MAX;

int findNext(vector<int>& v, vector<bool>& visited, int index){
    int res = -1;
    for(int i = index+1;i < v.size();i++){
        if(v[i] < v[index] && !visited[i]){
            res = i;
            break;
        }
    }
    return res;
}

// 数组下标
int getRes(vector<int>& v, vector<int>& t){



}

// void helper(int sum, int b, int cur, vector<bool>& visited, vector<int>& v){
//     if(sum > b){
//         return;
//     }
//     if(cur == -1){
//         res = min(res, );

//     }




// }

int main(){
    int n, b;
    cin >> n >> b;
    vector<int> p(n);
    vector<int> t(n);
    for(int i = 0;i < n;i++){
        cin >> p[i];
    }

    for(int i = 0;i < n;i++){
        cin >> t[i];
    }

    if(p[0] > b)
        cout << -1 << endl;
    else{
        int sum = p[0];
        vector<bool> visited(n , false);
        helper(sum, b, visited);
        cout << res << endl;
    }
    return 0;
}