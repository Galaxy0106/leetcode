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
    int dp(TreeNode* root, unordered_map<TreeNode*, int>& memo){
        if(root == nullptr)
            return 0;
        if(memo.count(root) != 0){
            return memo[root];
        }
        int do1 = 0, do2 = 0;
        int not_do = 0;
        // 偷当前的结点
        if(root->left != nullptr){
            do1 = dp(root->left->left, memo) + dp(root->left->right, memo);
        }

        if(root->right != nullptr){
            do2 = dp(root->right->left, memo) + dp(root->right->right, memo);
        }

        // 不偷当前的结点
        not_do = dp(root->left, memo) + dp(root->right, memo);
        memo[root] = max(root->val + do1 + do2, not_do);
        return memo[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo;
        int res = dp(root, memo);
        return res;
    }
};

int main(){

    return 0;
}