#include <bits/stdc++.h>

using namespace std;

void getVec(string& s, vector<long long>& v){
    string temp;
    long long a;
    for(int i = 0;i < s.size();i++){
        if(s[i] == ' '){
            stringstream ss;
            ss << temp;
            ss >> a;
            v.push_back(a);
            temp.clear();
        }
        else{
            temp.push_back(s[i]);
        }
    }
    stringstream ss;
    ss << temp;
    ss >> a;
    v.push_back(a);
    return;
}


int main(){
    // freopen("in.txt", "r", stdin);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<long long> nums1, nums2;
    getVec(s1, nums1);
    getVec(s2, nums2);

    int m = nums1.size();
    int n = nums2.size();

    vector<long long> v(m+n);
    int i = 0, j = 0;
    int k = 0;
    while(i < m && j < n){
        if(nums1[i] <= nums2[j]){
            v[k++] = nums1[i];
            i++;
        }
        else{
            v[k++] = nums2[j];
            j++;
        }
    }
    if(i == m){
        while(j < n){
            v[k++] = nums2[j];
            j++;
        }
    }
    else{
        while(i < m){
            v[k++] = nums1[i];
            i++;
        }
    }

    n = v.size();
    if(n % 2){
        printf("%.1lf\n", (double)v[n/2]);
    }
    else{
        double res = (v[n/2] + v[n/2 - 1]) / 2.0;
        printf("%.1lf\n", res);
    }

    return 0;
}