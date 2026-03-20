
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution
{
public:
  ListNode *sortList(ListNode *head)
  {
    if (!head || !head->next)
      return head;

    ListNode *slow = head;
    ListNode *fast = head->next; // 确保slow停在左半段的最后一个
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = nullptr; // 断开，不然递归就不是子串在递归了

    ListNode *left = sortList(head);
    ListNode *right = sortList(mid);

    return merge(left, right);
  }

  ListNode *merge(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(0, nullptr);
    ListNode *cur = &dummy;

    while (l1 && l2)
    {
      if (l1->val <= l2->val)
      {
        cur->next = l1;
        l1 = l1->next;
      }
      else
      {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }

    cur->next = l1 != nullptr ? l1 : l2;
    return dummy.next;
  }
};