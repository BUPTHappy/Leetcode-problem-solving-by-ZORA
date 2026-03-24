#include<vector>
#include <queue>
using namespace std;

class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    unordered_map<int, int> freq;
    for (int n : nums)
    {
      freq[n]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minQ;
    for (auto &[num, cnt] : freq)
    {
      minQ.push({cnt, num}); // 注意这里的顺序
      if (minQ.size() > k)
      {
        minQ.pop();
      }
    }

    vector<int> ans;
    while (!minQ.empty())
    {
      ans.push_back(minQ.top().second);
      minQ.pop();
    }
    return ans;
  }
};