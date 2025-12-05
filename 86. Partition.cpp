//
// Created by Zhuoer LIU on 2025-12-05.
//
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
 #include <ListNode>

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* leftHead=nullptr, *leftTail=nullptr;
        ListNode* rightHead=nullptr, *rightTail=nullptr;
        ListNode* next=nullptr;

        while(head!=nullptr){
            next = head->next;
            head->next = nullptr;

            if(head->val < x){
                if(leftHead==nullptr){
                    leftHead=head;
                }else{
                    leftTail->next = head;
                }
                leftTail = head;
            }else{
                if(rightHead==nullptr){
                    rightHead=head;
                }else{
                    rightTail->next=head;
                }
                rightTail=head;
            }
            head = next;
        }

        if(leftHead==nullptr){
            return rightHead;
        }
        leftTail->next=rightHead;
        return leftHead;
    }
};