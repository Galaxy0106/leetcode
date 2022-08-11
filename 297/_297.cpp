#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string str;
    void traverse1(TreeNode* root){
        if(root == nullptr){
            str += "#,";
            return;
        }
        str += to_string(root->val) + ",";
        traverse1(root->left);
        traverse1(root->right);
        return;
    }

    TreeNode* traverse2(list<string>& dataArray){
        if(dataArray.front() == "#"){
            dataArray.erase(dataArray.begin());
            return nullptr;
        }
        TreeNode *p = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        p->left = traverse2(dataArray);
        p->right = traverse2(dataArray);
        return p;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return str;
        traverse1(root);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return nullptr;
        list<string> dataArray;
        string temp;
        for(int i = 0;i < data.size();i++){
            if(data[i] == ','){
                dataArray.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(data[i]);
            }
        }
        if(!temp.empty()){
            dataArray.push_back(temp);
            temp.clear();
        }

        return traverse2(dataArray);
    }
};

void traverse(TreeNode *root){
    if(root == nullptr){
        cout << "#" << " ";
        return;
    }
    cout << root->val << " ";
    traverse(root->left);
    traverse(root->right);
    return;
}

int main(){
    Codec ser, deser;
    TreeNode *p = deser.deserialize("1,2,#,#,3,4,#,#,5,#,#,");
    // traverse(p);
    cout << ser.serialize(p);
    return 0;
}