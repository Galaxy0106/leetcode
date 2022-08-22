#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct rd{
    int k;
    int up;
    int down;
};

bool cmp(const rd &r1, const rd &r2){
    return r1.up < r2.up;
}

int findPos(vector<rd> &rds, int k){
    int pos = -1;
    for(int i = 0;i < rds.size();i++){
        if(rds[i].k == k){
            pos = i;
            break;
        }
    }
    return pos;
}


int minStone(int n, vector<int>& nums1, vector<int>& nums2){
    int res = -1;
    vector<rd> rds;
    int k = 0;
    rd rd_temp;
    sort(nums1.begin(), nums1.end());
    // sort(nums2.begin(), nums2.end());
    for(int i = 0;i < nums1.size();i++){
        if(nums1[i] != k){
            if(k != 0)
                rds.push_back(rd_temp);
            k = nums1[i];
            rd_temp.k = k;
            rd_temp.up = 1;
            rd_temp.down = 0;
        }
        else
            rd_temp.up++;
    }
    rds.push_back(rd_temp);
    // sort(rds.begin(), rds.end());
    for(int i = 0;i < nums2.size();i++){
        int pos = findPos(rds, nums2[i]);
        if(pos != -1)
            rds[pos].down++;
        else{
            rd rd_temp2;
            rd_temp2.k = nums2[i];
            rd_temp2.up = 0;
            rd_temp2.down = 1;
            rds.push_back(rd_temp2);
        }
    }
    sort(rds.begin(), rds.end(), cmp);
    for(int i = 0;i < rds.size();i++){
        if(rds[i].up + rds[i].down >= n/2){
            res = rds[i].down;
            break;
        }
    }
    return res;
}

int main(){
    int n = 6;
    vector<int> nums1 = {1, 3, 2, 4, 5, 6};
    vector<int> nums2 = {3, 4, 5, 2, 3, 6};
    cout << minStone(n, nums1, nums2);
    return 0;
}