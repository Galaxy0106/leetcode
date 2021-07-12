#include<iostream>
#include<vector>
#include<stack>

using namespace std;
/**
 * Definition for a binary tree node.
 */
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;       
        while (root != nullptr || !stk.empty())
        {
            while(root){
                stk.push(root);
                root = root->left;
            }
            if(!stk.empty()){
                TreeNode* p = stk.top();
                res.push_back(p->val);
                stk.pop();
                p = p->right;
            }
        }
        return res;
    }
};

int main(){


    return 0;
}