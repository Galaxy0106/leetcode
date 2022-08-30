#include <bits/stdc++.h>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i = 0;i < nums.size();i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size() < size){
            pq.push(val);
        }
        else{
            if(val > pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};


int main(){

    return 0;
}