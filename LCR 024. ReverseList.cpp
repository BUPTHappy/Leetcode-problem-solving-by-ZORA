//
// Created by Zhuoer LIU on 2025-12-04.
//
#include <ListNode>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next = nullptr;

        while(head!=nullptr){
            next = head->next;
            head->next=pre;
            pre=head;
            head=next;
        }

        return pre;
    }
};