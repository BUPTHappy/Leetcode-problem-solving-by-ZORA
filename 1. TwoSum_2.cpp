#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> hashMap; // 存储元素值和索引
    for (int i = 0; i < nums.size(); i++)
    {
      int complement = target - nums[i];
      if (hashMap.find(complement) != hashMap.end())
      {
        return {hashMap[complement], i}; // 找到匹配项，返回索引
      }
      hashMap[nums[i]] = i; // 存储当前值及其索引
    }
    return {}; // 题目保证有解，实际上不会执行到这里
  }
};
