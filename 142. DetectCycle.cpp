//
// Created by Zhuoer LIU on 2025-11-27.
//
#include<ListNode>

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        bool is_first_loop=true; //用于区分第一次循环

        while(fast!=slow || is_first_loop){
            if(fast==nullptr || fast->next == nullptr){
                return nullptr;
            }
            fast=fast->next->next;
            slow=slow->next;
            is_first_loop=false;
            //之后从第二次开始，只有再当fast==slow && is_first_circle=false 时才退出
        }

        //寻找节点
        fast=head; //让快指针回到起点
        //只有上面的跑得过，说明他俩相遇过，才会跑下面，让他们再跑一次相遇
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};