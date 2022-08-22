#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.count(val))
            return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)){
            int index = mp[val];
            int len = nums.size();
            swap(nums[index], nums[len-1]);
            mp[nums[index]] = index;
            nums.pop_back();
            mp.erase(val);
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        int k = rand() % nums.size();
        return nums[k];
    }
};

int main(){
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << endl;
    cout << obj->remove(2) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->getRandom() << endl;
    cout << obj->remove(1) << endl;
    cout << obj->insert(2) << endl;
    cout << obj->getRandom() << endl;
    return 0;
}