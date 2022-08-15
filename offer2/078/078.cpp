#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct node {
        int val;
        ListNode *ptr;
        bool operator < (const node& nd) const{
            return val > nd.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<node> pq;
        // 初始化优先队列
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        for(int i = 0;i < lists.size();i++){
            if(lists[i] != nullptr)
                pq.push({lists[i]->val, lists[i]});
        }
        while(!pq.empty()){
            ListNode *pTemp = pq.top().ptr;
            p->next = pTemp;
            p = p->next;
            pq.pop();
            pTemp = pTemp->next;
            if(pTemp)
                pq.push({pTemp->val, pTemp});
        }
        return dummy->next;
    }
};

int main(){


    return 0;
}