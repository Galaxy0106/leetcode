#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head){
    if(head == NULL || head->next == NULL)
        return true;
    ListNode *p = head;
    int len = 0, count = 0;
    while (p){
        p = p->next;
        len++;
    }
    p = head;
    while (++count < (len/2 + 1))
    {
        p = p->next;
    }
    while (p->next)
    {   
        ListNode *q = p->next->next;
        p->next->next = p;
        p = 
    }

} 


int main(){

    return 0;
}