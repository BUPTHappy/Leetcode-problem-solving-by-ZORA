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

static int yes;
static int no;

class Solution
{
public:
  int rob(TreeNode *root)
  {
    f(root);
    return max(yes, no);
  }

  void f(TreeNode *cur)
  {
    // 这相当于是base case了，因为这种情况是叶节点，就是递归到最下面了
    if (!cur)
    {
      yes = 0;
      no = 0;
    }
    else
    {
      int y = cur->val;
      int n = 0;
      f(cur->left); // 左子树走完
      y += no;      // 当前根能更新一下我的y和n,是加进去
      n += max(yes, no);
      f(cur->right); // 右子树走完
      y += no;
      n += max(yes, no);

      // 每个子树结束，会把自己的情况更新到全局变量
      yes = y;
      no = n;
    }
  }
};