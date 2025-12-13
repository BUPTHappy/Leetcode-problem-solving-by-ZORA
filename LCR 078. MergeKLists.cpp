//
// Created by Zhuoer LIU on 2025-12-13.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //小根堆来做，时间复杂度O(nlogk),空间复杂度O(k)
        auto comp =[](ListNode*a, ListNode*b){
            return a->val > b->val; //比较器返回true表示第一个参数优先级更低
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> min_heap(comp);

        for(ListNode* node:lists){
            if(node) min_heap.push(node);
        }
        if(min_heap.empty()){
            return nullptr;
        }

        //先弹出第一个节点做头部
        ListNode* h = min_heap.top(); //注意c++这里是pop不会弹出东西的
        min_heap.pop();

        ListNode* p = h;
        //要把头的第二个先带进去
        if(p->next!=nullptr){
            min_heap.push(p->next);
        }

        //然后循环，小根堆先弹出再压入新的
        while(!min_heap.empty()){
            ListNode* curr = min_heap.top();
            min_heap.pop();
            p->next = curr; //把弹出的连起来
            p = curr; //这里相当于p++
            if(curr->next!=nullptr){
                min_heap.push(curr->next);
            }
        }
        return h;
    }
};