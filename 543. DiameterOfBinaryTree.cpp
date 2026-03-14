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

class Solution
{
public:
  int ans = 0;

  int diameterOfBinaryTree(TreeNode *root)
  {
    deep(root);
    return ans;
  }

  int deep(TreeNode *root)
  {
    if (!root)
      return 0;

    int leftDeep = deep(root->left);
    int rightDeep = deep(root->right);

    ans = max(ans, leftDeep + rightDeep);

    return (max(leftDeep, rightDeep) + 1);
  }
};