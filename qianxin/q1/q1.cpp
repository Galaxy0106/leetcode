#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算dag 路径上起始到目的节点的路径数目
     * @param nodes int整型vector<vector<>> 第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ），若为空，就是没有下一个节点了。
     * @return int整型
     */
    int res;
    void helper(vector<vector<int>>& nodes, vector<bool>& visited, int cur){
        int n = nodes.size();
        if(cur == n-1){
            res++;
            return;
        }

        visited[cur] = true;
        for(int i = 0;i < nodes[cur].size();i++){
            if(!visited[nodes[cur][i]]){
                helper(nodes, visited, nodes[cur][i]);
            }
        }
        visited[cur] = false;
        return;
    }

    int DagPathNum(vector<vector<int> >& nodes) {
        // write code here
        int n = nodes.size();
        res = 0;
        vector<bool> visited(n, false);
        helper(nodes, visited, 0);
        return res;
    }
};

int main(){
    vector<vector<int>> nodes = {{1,2,3}, {3}, {3}, {4}, {}};
    Solution sol;
    cout << sol.DagPathNum(nodes);
    return 0;
}