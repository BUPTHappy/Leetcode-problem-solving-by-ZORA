#include <unordered_map>
using namespace std;

class LRUCache
{
private:
  struct DoubleNode
  {
    int key;
    int value;
    DoubleNode *last;
    DoubleNode *next;

    DoubleNode(int k, int v) : key(k), value(v), last(nullptr), next(nullptr) {}
  };

  struct DoubleList
  {
    DoubleNode *head;
    DoubleNode *tail;
    DoubleList() : head(nullptr), tail(nullptr) {}

    void addNode(DoubleNode *node)
    {
      if (!node)
        return;
      if (!head)
      {
        head = node;
        tail = node;
      }
      else
      {
        tail->next = node;
        node->last = tail;
        tail = node;
      }
    }

    void moveNodeToTail(DoubleNode *node)
    {
      if (tail == node)
        return;
      if (head == node)
      {
        head = node->next;
        head->last = nullptr;
      }
      else
      {
        node->last->next = node->next;
        node->next->last = node->last;
      }

      node->last = tail;
      node->next = nullptr;
      tail->next = node;
      tail = node;
    }

    DoubleNode *removeHead()
    {
      if (!head)
        return nullptr;
      DoubleNode *ans = head;
      if (head == tail)
      {
        head = tail = nullptr;
      }
      else
      {
        head = ans->next;
        head->last = nullptr;
        ans->next = nullptr;
      }
      return ans;
    }
  };

  unordered_map<int, DoubleNode *> keyNodeMap;
  DoubleList nodeList;
  int capacity;

public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key)
  {
    if (!keyNodeMap.count(key))
    {
      return -1;
    }
    DoubleNode *node = keyNodeMap[key];
    nodeList.moveNodeToTail(node);
    return node->value;
  }

  void put(int key, int value)
  {
    if (keyNodeMap.count(key))
    {
      DoubleNode *node = keyNodeMap[key];
      node->value = value;
      nodeList.moveNodeToTail(node);
    }
    else
    {
      if ((int)keyNodeMap.size() == capacity)
      {
        DoubleNode *removed = nodeList.removeHead();
        keyNodeMap.erase(removed->key);
        delete removed; // 这里防止内存泄漏
      }
      DoubleNode *newnode = new DoubleNode(key, value); // 记得关键字new
      keyNodeMap[key] = newnode;
      nodeList.addNode(newnode);
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */