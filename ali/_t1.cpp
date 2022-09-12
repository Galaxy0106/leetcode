#include <bits/stdc++.h>

using namespace std;


struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

/*
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

     A 
   /     \
  B         C
/    \    /   \
D   E    F   G 
A.next = null;
B.next = &C;
C.next = null;
E.next = &F;
*/



class Solution {
public:    
    Node* connect(Node* root) { 
        if(root == nullptr)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            Node *temp1 = nullptr, *temp2 = nullptr;
            for(int i = 0;i < sz-1;i++){
                temp1 = q.front();
                q.pop();
                temp2 = q.front();
                temp1->next = temp2;
                if(temp1->left)
                    q.push(temp1->left);
                if(temp1->right)
                    q.push(temp1->right);
            }
            temp1 = q.front();
            q.pop();
            if(temp1->left)
                q.push(temp1->left);
            if(temp1->right)
                q.push(temp1->right);
        }
        return root;
    }
};



int main(){


    return 0;
}