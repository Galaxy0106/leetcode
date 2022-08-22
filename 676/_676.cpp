#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    bool isWord;
    TrieNode* children[26];
    TrieNode(){
        isWord = false;
        for(int i = 0;i < 26;i++){
            children[i] = nullptr;
        }
    }
};

class MagicDictionary {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i = 0;i < dictionary.size();i++){
            TrieNode *p = root;
            for(auto ch : dictionary[i]){
                if(p->children[ch - 'a'] == nullptr)
                    p->children[ch - 'a'] = new TrieNode();
                p = p->children[ch - 'a'];
            }
            p->isWord = true;
        }
    }
    
    bool dfs(TrieNode* root, string word, int pos, int edit){
        if(root == nullptr)
            return false;
        if(root->isWord == true && pos == word.size() && edit == 1)
            return true;
        if(pos < word.size() && edit <= 1){
            bool found = false;
            for(int i = 0;i < 26 && !found;i++){
                int edit = (i == word[i] - 'a') ? edit : edit+1;
                found = dfs(root->children[i], word, i+1, edit);
            }
            return found;
        }
        return false;
    }

    bool search(string searchWord) {
        return dfs(root, searchWord, 0, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main(){
    MagicDictionary* obj = new MagicDictionary();
    vector<string> dict = {"hello", "leetcode"};
    obj->buildDict(dict);
    cout << obj->search("hello");
    cout << obj->search("hhllo");
    cout << obj->search("hell");
    cout << obj->search("leetcoded");
    return 0;
}