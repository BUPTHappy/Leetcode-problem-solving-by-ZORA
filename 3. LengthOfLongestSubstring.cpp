#include<iostream>
#include<unordered_set>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_set<char> charset;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.size(); right++)
    {

      while (charset.find(s[right]) != charset.end())
      {
        charset.erase(s[left]);
        left++; // 动态调整左指针之后，窗口缩小
      }

      charset.insert(s[right]);
      maxLength = max(maxLength, right - left + 1);
    }
    return maxLength;
  }
};