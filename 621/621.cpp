#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isEnd(vector<int>& record){
        for(int i = 0;i < record.size();i++){
            if(record[i] == 0)
                return false;
        }
        return true;
    }

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> record(tasks.size(), 0);        
        int ans = 0;
        // traverse
        char lastTask = '#';
        bool isReady = true;
        int cnt = 0;
        while(!isEnd(record)){
            for(int i = 0;i < record.size();i++){
                if(record[i] == 0){
                    if(record[i] == lastTask){
                        
                    }

                }
            }
        }
    }
};

int main(){


    return 0;
}