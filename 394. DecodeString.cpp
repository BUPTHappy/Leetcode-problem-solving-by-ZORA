#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    stack<int> nums;
    stack<string> stSt;
    int num = 0;
    string cur = "";

    for (char c : s)
    {
      if (isdigit(c))
      {
        num = num * 10 + c - '0';
      }
      else if (c == '[')
      {
        nums.push(num);
        stSt.push(cur);
        num = 0;
        cur = "";
      }
      else if (c == ']')
      {
        int k = nums.top();
        nums.pop();
        string prev = stSt.top();
        stSt.pop();
        for (int i = 0; i < k; i++)
        {
          prev += cur;
        }
        cur = prev;
      }
      else
      {
        cur += c;
      }
    }
    return cur;
  }
};