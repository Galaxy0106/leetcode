#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //p1为快指针，P2为慢指针
        int i = 0;
        ListNode *p1,*p2;
        p1 = head, p2 = head;
        while(i++ < n){
            p1 = p1->next;
        }
        //判断要删除的是否为头结点
        if(p1->next == nullptr){
            head = p2->next;
            p2->next = nullptr;
            free(p2);
            return head;
        }
        ListNode *pre2 = nullptr;
        while(p1->next != nullptr){
            pre2 = p2;
            p1 = p1->next;
            p2 = p2->next;
        }
        pre2->next = p2->next;
        p2->next = nullptr;
        free(p2);
        return head;
    }
};

int main(){

    return 0;
}