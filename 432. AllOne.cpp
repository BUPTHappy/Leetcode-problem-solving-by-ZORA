#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class AllOne
{
  class Bucket
  {
    public:
      unordered_set<string> set;
      int cnt;
      Bucket *last;
      Bucket *next;

      Bucket(string s, int c) : cnt(c), last(nullptr), next(nullptr)
      {
        set.insert(s);
      }
  };

public:
  void insert(Bucket *cur, Bucket *pos)
  { // 告诉你现在有一个cur，然后你要把pos插入到cur后面
    cur->next->last = pos;
    pos->next = cur->next;
    cur->next = pos;
    pos->last = cur;
  }

  void remove(Bucket *cur)
  { // 当前有一个桶cur，要删掉
    cur->last->next = cur->next;
    cur->next->last = cur->last;
  }

  Bucket *head; // 放一个词频为0的左挡板
  Bucket *tail; // 放一个词频为int最大值的右挡板
  unordered_map<string, Bucket *> cntMap;

  AllOne()
  { // 构造函数初始化一下头和尾桶（作为挡板），然后把链接连起来
    head = new Bucket("", 0);
    tail = new Bucket("", INT_MAX);
    head->next = tail;
    tail->last = head;
  }

  void inc(string key)
  {

    if (cntMap.find(key) == cntMap.end())
    { // 里面原本没有key
      // 就是处理1桶的存在与否
      if (head->next->cnt == 1)
      {
        head->next->set.insert(key);
        cntMap[key] = head->next;
      }
      else
      {
        Bucket *bucket1 = new Bucket(key, 1);
        insert(head, bucket1);
        cntMap[key] = bucket1;
      }
    }
    else
    { // 里面本来就有key
      Bucket *curBucket = cntMap[key];
      // 就是处理右移1个桶的存在与否
      if (curBucket->next->cnt == curBucket->cnt + 1)
      {
        curBucket->next->set.insert(key);
        cntMap[key] = curBucket->next;
      }
      else
      {
        Bucket *bucketPlus = new Bucket(key, curBucket->cnt + 1);
        insert(curBucket, bucketPlus);
        cntMap[key] = bucketPlus;
      }

      // 放好新位置之后，要把它从原来的移除
      curBucket->set.erase(key);
      if (curBucket->set.empty())
      {
        remove(curBucket);
      }
    }
  }

  void dec(string key)
  {
    // 题目默认都是有key的
    Bucket *bucketCurr = cntMap[key];
    if (bucketCurr->cnt == 1)
    { // 1的左移是0，一定存在，就直接处理了
      cntMap.erase(key);
    }
    else
    {
      // 处理左移1个桶的存在与否
      if (bucketCurr->last->cnt == bucketCurr->cnt - 1)
      {
        bucketCurr->last->set.insert(key);
        cntMap[key] = bucketCurr->last;
      }
      else
      {
        Bucket *bucketMinus = new Bucket(key, bucketCurr->cnt - 1);
        insert(bucketCurr->last, bucketMinus);
        cntMap[key] = bucketMinus;
      }
    }

    // 放好新位置之后，要把它从原来的移除
    bucketCurr->set.erase(key);
    if (bucketCurr->set.empty())
    {
      remove(bucketCurr);
    }
  }

  string getMaxKey()
  {
    return *tail->last->set.begin(); // 解引用
  }

  string getMinKey()
  {
    return *head->next->set.begin();
  }
};

