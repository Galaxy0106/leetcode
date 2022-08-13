#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void traverse(vector<vector<int>>& graph, vector<int>& path, int k){
        int n = graph.size();
        path.push_back(k);
        if(k == n-1){
            res.push_back(path);
        }
        for(int i = 0;i < graph[k].size();i++){
            traverse(graph, path, graph[k][i]);
        }
        path.pop_back();
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        traverse(graph, path, 0);
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    sol.allPathsSourceTarget(graph);
    return 0;
}