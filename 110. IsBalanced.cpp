#include <algorithm>
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

static bool balance;

class Solution
{
public:
  bool isBalanced(TreeNode *root)
  {
    balance = true;
    height(root);
    return balance;
  }

  int height(TreeNode *root)
  {
    if (!balance || !root)
    {
      return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) > 1)
    {
      balance = false;
    }
    return max(lh, rh) + 1;
  }
};