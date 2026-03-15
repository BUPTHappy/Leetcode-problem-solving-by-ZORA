
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode dummy(0, head); // 构造一个dummy虚假头节点，防止删除第一个还得特判
    ListNode *fast = &dummy;
    ListNode *slow = &dummy;

    for (int i = 0; i <= n; i++)
    { // 取等号是因为，我们加了dummy
      fast = fast->next;
    }
    while (fast)
    {
      fast = fast->next;
      slow = slow->next;
    }
    // 此时slow来到的就是需要删除节点的前一个
    ListNode *remove = slow->next;
    slow->next = remove->next;
    remove->next = nullptr;

    return dummy.next;
  }
};