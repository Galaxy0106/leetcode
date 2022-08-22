#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class CodeC{
public:
    string str;
    string traverse1(TreeNode* root){
        if(root == nullptr){
            return "#";
        }
        string leftStr = traverse1(root->left);
        string rightStr = traverse1(root->right);
        string subStr = leftStr + "," + rightStr + "," + to_string(root->val);
        return subStr;
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

    string serialize(TreeNode* root) {
        string str = traverse1(root);
        return str;
    }

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


int main(){
    CodeC ser,deser;
    TreeNode *p = deser.deserialize("1,2,4,#,#,#,3,2,4,#,#,#,4,#,#,");
    cout << ser.serialize(p);
    return 0;
}