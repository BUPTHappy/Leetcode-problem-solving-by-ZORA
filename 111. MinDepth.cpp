#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
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
  int minDepth(TreeNode *root)
  {
    if (!root)
    {
      return 0;
    }
    if (!root->left && !root->right)
    {
      return 1;
    }
    // 先把左右的最大深度设置成最大值，这样不会干扰
    int ldeep = INT_MAX;
    int rdeep = INT_MAX;
    if (root->left)
    {
      ldeep = minDepth(root->left); // 递归
    }
    if (root->right)
    {
      rdeep = minDepth(root->right);
    }
    return min(ldeep, rdeep) + 1;
  }
};