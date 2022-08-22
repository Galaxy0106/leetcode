#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// int main(){
//     int n;
//     vector<int> nums1, nums2;
//     cin >> n;
//     for(int i = 0;i < n;i++){
//         int k;
//         cin >> k;
//         nums1.push_back(k);
//     }

//     for(int i = 0;i < n;i++){
//         int k;
//         cin >> k;
//         nums2.push_back(k);
//     }

//     vector<pair<int, int>> arr1, arr2;
//     sort(nums1.begin(), nums1.end());
//     sort(nums2.begin(), nums2.end());

//     pair<int, int> p;
//     int last = 0;    
//     for(int i = 0;i < nums1.size();i++){
//         if(nums1[i] != last){
//             arr1.push_back(p);
//             p.first = nums1[i];
//             p.second = 1;
//         }
//         p.second++;
//     }
//     arr1.push_back(p);

//     last = 0;    
//     for(int i = 0;i < nums2.size();i++){
//         if(nums2[i] != last){
//             arr2.push_back(p);
//             p.first = nums2[i];
//             p.second = 1;
//             last = p.first;
//         }
//         p.second++;
//     }
//     arr2.push_back(p);

//     for(int i = 0;i < nums1.size();i++){

//     }


//     return 0;
// }