#include<algorithm>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static long g_min, g_max;
class Solution
{
public:
  bool isValidBST(TreeNode *root)
  {
    if (!root)
    {
      g_min = LONG_MAX;
      g_max = LONG_MIN;
      return true;
    }

    bool lok = isValidBST(root->left);
    long lmin = g_min;
    long lmax = g_max;
    bool rok = isValidBST(root->right);
    long rmin = g_min;
    long rmax = g_max;

    g_min = min(min(lmin, rmin), (long)root->val);
    g_max = max(max(lmax, rmax), (long)root->val);

    return rok && lok && (lmax < root->val) && (rmin > root->val);
  }
};