#include<vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    unordered_set<int> s(nums.begin(), nums.end());
    int maxLen = 0;

    for (int num : s)
    {
      // 只有当 num-1 不存在时，才作为序列起点
      if (!s.count(num - 1))
      {
        int cur = num;
        int len = 1;

        while (s.count(cur + 1))
        {
          cur++;
          len++;
        }

        maxLen = max(maxLen, len);
      }
    }
    return maxLen;
  }
};
