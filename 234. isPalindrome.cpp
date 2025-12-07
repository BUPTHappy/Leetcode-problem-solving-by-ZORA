//
// Created by Zhuoer LIU on 2025-12-07.
//
#include<ListNode>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //1.用快慢指针找中点
        ListNode*slow = head, *fast=head;
        while(fast->next && fast->next->next){ //确保fast既能走一步，也能走两步
            slow = slow->next;
            fast = fast->next->next;
        }

        //2. 翻转后半段(单链表反转实现)
        ListNode *secondHalf = reverseList(slow->next);
        slow->next=nullptr;

        //3. 比较
        ListNode*p1 = head, *p2 = secondHalf;
        bool result = true;
        while(p2){
            if(p1->val !=p2->val){
                result=false;
                break;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return result;
    }

private:
    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* next = nullptr;

        while(head){
            next = head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};