#include <bits/stdc++.h>

using namespace std;

vector<int> temp;

void merge(vector<int>& nums, int lo, int mid, int hi){
    for(int i = lo;i <= hi;i++){
        temp[i] = nums[i];
    }
    int i = lo, j = mid + 1;
    int pos = lo;
    while(i <= mid && j <= hi){
        if(temp[i] < temp[j]){
            nums[pos++] = temp[i++];
        }
        else{
            nums[pos++] = temp[j++];
        }
    }
    if(i <= mid){
        while(i <= mid){
            nums[pos++] = temp[i++];
        }
    }
    else{
        while(j <= hi){
            nums[pos++] = temp[j++];
        }
    }
    return;
}


void mergeSort(vector<int>& nums, int l, int r){
    if(l == r)
        return;
    int mid = l + (r - l)/2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid+1, r);
    merge(nums, l, mid, r);
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
    return;
}

// int main(){
//     vector<int> nums = {1, 3, 2, 7, 4, 6, 5};
//     int n = nums.size();
//     temp.resize(n);
//     mergeSort(nums, 0, n-1);
//     for(auto num : nums){
//         cout << num << " ";
//     }
//     cout << endl;
//     return 0;
// }