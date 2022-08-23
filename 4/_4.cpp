#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index1 = 0;
        int index2 = 0;
        int len = nums1.size() + nums2.size();
        int mid;
        vector<int> mids;
        for(auto i = 0;i < len;i++){
            int num;
            if(index1 == nums1.size()){
                num = nums2[index2];
                ++index2;
            }
            else if(index2 == nums2.size()){
                num = nums1[index1];
                ++index1;
            }
            else{
                if(nums1[index1] > nums2[index2]){
                    num = nums2[index2];
                    ++index2;
                }
                else{
                    num = nums1[index1];
                    ++index1;
                }
            }
            if(i == len/2 || i == (len-1)/2){
                if(!(len % 2)){
                    mids.push_back(num);
                }
                else{
                    mid = num;
                }
            }
            cout<<num<<endl; 
        }
        if(mids.size() > 0){
            return (mids[0] + mids[1])/2.0;
        }
        else{
            return mid;
        }
    }
};

int main(){
    Solution sol;
    vector<int> v1 = {0,0,0,0,0};
    vector<int> v2 = {-1,0,0,0,0,0,1};
    sol.findMedianSortedArrays(v1,v2);
    return 0;
}