#include<iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* createNode(int x){
    ListNode node(x);
    ListNode *p = &node;
    return p;
}