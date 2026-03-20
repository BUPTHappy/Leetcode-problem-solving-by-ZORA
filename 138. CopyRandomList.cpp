
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (!head)
      return nullptr;
    Node *cur = head;
    Node *next = nullptr;

    while (cur)
    {
      next = cur->next;
      cur->next = new Node(cur->val);
      cur->next->next = next;
      cur = next;
    }

    cur = head;
    Node *copy = nullptr;

    while (cur)
    {
      next = cur->next->next;
      copy = cur->next;
      copy->random = cur->random != nullptr ? cur->random->next : nullptr;
      cur = next;
    }

    Node *ans = head->next;
    cur = head;

    while (cur)
    {
      next = cur->next->next;
      copy = cur->next;
      cur->next = next;
      copy->next = next != nullptr ? next->next : nullptr;
      cur = next;
    }

    return ans;
  }
};