#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> build(int lo, int hi) {
        vector<TreeNode*> res;
        if(lo > hi){
            res.push_back(nullptr);
            return res;
        }
        for(int i = lo;i <= hi;i++){
            vector<TreeNode*> leftNodes = build(lo, i-1);
            vector<TreeNode*> rightNodes = build(i+1, hi);
            for(auto leftNode : leftNodes){
                for(auto rightNode : rightNodes){
                    TreeNode *root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0)
            return res;
        return build(1, n);
    }
};

int main(){
    Solution sol;
    sol.generateTrees(3);
    return 0;
}