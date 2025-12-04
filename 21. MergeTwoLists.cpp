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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans;
        if(list1==nullptr || list2==nullptr){
            return list1==nullptr ? list2 : list1;
        }
        ans = list1->val <= list2->val ? list1 : list2;

        ListNode* curr1 = ans->next;
        ListNode* curr2 = list1 == ans ? list2 : list1;
        ListNode* pre = ans;
        while(curr1!=nullptr && curr2!=nullptr){
            if(curr1->val <= curr2->val){
                pre->next = curr1;
                curr1=curr1->next;
            }else{
                pre->next = curr2;
                curr2=curr2->next;
            }
            pre = pre->next;
        }
        pre->next = curr1 != nullptr ? curr1 : curr2;
        return ans;
    }
};