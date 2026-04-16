#include<vector>
#include<string>
using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    if (strs.empty())
      return "";
    for (int i = 0; i < strs[0].size(); i++)
    { // 遍历第一个string的每个元素
      char c = strs[0][i];
      for (int j = 1; j < strs.size(); j++)
      { // 比较每个后面的字符串的对应的元素
        if (i >= strs[j].size() || strs[j][i] != c)
        {
          // 出现不匹配或者越界，返回前缀
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0]; // 都匹配上了，就全部返回
  }
};