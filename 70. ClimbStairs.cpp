class Solution
{
public:
  int climbStairs(int n)
  {
    if (n <= 2)
      return n;
    int prev1 = 2, prev2 = 1; // prev1:ways to reach (i-1); prev2: ways to reach(i-2)
    int curr;

    for (int i = 3; i <= n; i++)
    {
      curr = prev1 + prev2;
      prev2 = prev1;
      prev1 = curr;
    }

    return curr;
  }
};