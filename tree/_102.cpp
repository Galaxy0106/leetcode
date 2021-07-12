#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        // int hash_table[1000] = {0};
        queue<pair<TreeNode*, int>> q;

        pair<TreeNode*, int> p;
        vector<int> v;
        p.first = root;
        p.second = 0;
        q.push(p);
        while(!q.empty())
        {
            //get the front of queue
            pair<TreeNode*, int> pfront = q.front();
            q.pop();
            int level = pfront.second;
            // ++hash_table[level];
            if(!v.empty()){
                if(*v.end() == pfront.first->val){
                    v.push_back(pfront.first->val);
                }
                else{
                    res.push_back(v);
                    v.empty();
                    v.push_back(pfront.first->val);
                }
            }
            else{
                v.push_back(pfront.first->val);
            }

            if(pfront.first->left != nullptr){
                p.first = pfront.first->left;
                p.second = pfront.second + 1;
                q.push(p);
            }

            if(pfront.first->right != nullptr){
                p.first = pfront.first->right;
                p.second = pfront.second + 1;
                q.push(p);
            }
        }
        return res;
    }
};

 int main(){

     return 0;
 }