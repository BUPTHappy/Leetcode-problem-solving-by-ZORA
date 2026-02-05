#include <queue>
using namespace std;

class MedianFinder
{
public:
  /** initialize your data structure here. */
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;

  MedianFinder()
  {
  }

  void addNum(int num)
  {
    if (max_heap.empty() || num <= max_heap.top())
    {
      max_heap.push(num);
    }
    else
    {
      min_heap.push(num);
    }
    balance();
  }

  double findMedian()
  {
    if (max_heap.size() == min_heap.size())
    {
      return (double)(max_heap.top() + min_heap.top()) / 2;
    }
    else
    {
      return max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
    }
  }

private:
  void balance()
  {
    if (abs((int)max_heap.size() - (int)min_heap.size()) == 2)
    {
      if (max_heap.size() > min_heap.size())
      {
        int move = max_heap.top();
        max_heap.pop();
        min_heap.push(move);
      }
      else if (min_heap.size() > max_heap.size())
      {
        int move = min_heap.top();
        min_heap.pop();
        max_heap.push(move);
      }
    }
  }
};
