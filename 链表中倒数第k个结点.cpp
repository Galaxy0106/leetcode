#include<iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(k <= 0)
            return NULL;
        ListNode *p = head, *q = head;
        int num = 0;
        while(p){
            p = p->next;
            if(num >= k)
                q = q->next;
            num++;
        }
        if(k > num)
            return NULL;
        else
            return q;
    }
};