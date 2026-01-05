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
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    ListNode *start = head;
    ListNode *end = teamend(start, k);
    if (end == nullptr)
    {
      return head;
    }

    // 第一组特殊处理，它的尾巴就是整个的头
    head = end;
    reverse(start, end);

    ListNode *lastTeamEnd = start;
    while (lastTeamEnd->next != nullptr)
    {
      start = lastTeamEnd->next;
      end = teamend(start, k);
      if (end == nullptr)
      {
        return head;
      }
      reverse(start, end);
      lastTeamEnd->next = end;
      lastTeamEnd = start;
    }
    return head;
  }

  ListNode *teamend(ListNode *s, int k)
  {
    while (--k != 0 && s != nullptr)
    {
      s = s->next;
    }
    return s;
  }

  void reverse(ListNode *s, ListNode *e)
  {
    e = e->next;
    ListNode *pre = nullptr;
    ListNode *next = nullptr;
    ListNode *cur = s;
    while (cur != e)
    {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }

    s->next = e;
  }
};