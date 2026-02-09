#include <algorithm>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    while (root != p && root != q)
    {
      if ((min(p->val, q->val) < root->val) && (root->val < max(p->val, q->val)))
      {
        break;
      }
      else
      {
        root = root->val < min(p->val, q->val) ? root->right : root->left;
      }
    }
    return root;
  }
};