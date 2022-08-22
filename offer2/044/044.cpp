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


class BinaryTree {
public:
// 构造函数
    BinaryTree(): root(nullptr){}
// 析构函数
    ~BinaryTree(){}

// 使用前序遍历创建二叉树
    void createTreePreOrder(){
        
    }


private:
    TreeNode *root;
};


int main(){

    return 0;
}