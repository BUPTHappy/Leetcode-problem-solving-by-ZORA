using namespace std;

// Definition for a Node.
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
    if (head == nullptr)
    {
      return nullptr;
    }
    Node *cur = head;
    Node *next = nullptr;

    // 把复制节点放到中间，连接起来
    while (cur != nullptr)
    {
      next = cur->next;
      cur->next = new Node(cur->val);
      cur->next->next = next;
      cur = next;
    }

    cur = head;
    Node *copy = nullptr;

    // 复制random指针
    while (cur != nullptr)
    {
      next = cur->next->next;
      copy = cur->next;
      copy->random = cur->random != nullptr ? cur->random->next : nullptr;
      cur = next;
    }

    Node *ans = head->next;
    cur = head;

    // 解耦两个链
    while (cur != nullptr)
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
