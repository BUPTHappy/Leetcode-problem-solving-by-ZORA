#include<climits>
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

// 思路：后序遍历，每个节点计算两件事:
// 1. 向上贡献：我能给父节点提供的最大单边路径值（只能选左或右一边，或不选）
// 2. 本地更新答案：经过我的最大路径 = 左贡献 + 我 + 右贡献
class Solution
{
  int ans = INT_MIN;

  int dfs(TreeNode *root)
  {
    if (!root)
      return 0;

    int left = max(dfs(root->left), 0); // 这里注意，如果负数的话我就不往上贡献了
    int right = max(dfs(root->right), 0);

    ans = max(ans, left + root->val + right); // 更新答案
    return root->val + max(left, right);      // 向上贡献
  }

public:
  int maxPathSum(TreeNode *root)
  {
    dfs(root);
    return ans;
  }
};