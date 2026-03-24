#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st; // 一个单调栈，维护还没处理到的下一个比他高的温度的索引

    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && temperatures[i] > temperatures[st.top()])
      {
        int idx = st.top();
        st.pop();
        ans[idx] = i - idx;
      }
      st.push(i);
    }
    return ans;
  }
};