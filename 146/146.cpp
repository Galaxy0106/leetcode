#include<bits/stdc++.h>

using namespace std;

class LRUCache {
public:
    // 记录 key 的 队列
    queue<int> lru_q;
    // 队列 的 容量
    int capacity;
    // hash table
    int record[10000];

    LRUCache(int capacity){
        this->capacity = capacity;
        // 初始值为 -1
        memset(record, -1, 10000);
    }
    
    int get(int key) {
        if(lru_q.size() < capacity){

        }

    }
    
    void put(int key, int value) {
        
    }
};

int main(){
    // queue<pair<int, int>> lru_q;

    return 0;
}