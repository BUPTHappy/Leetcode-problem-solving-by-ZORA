#include <unordered_map>
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
  unordered_map<long long, int> prefix;
  int target;

  int dfs(TreeNode *node, long long curr)
  { // 这个累加和的类型需要注意
    if (!node)
      return 0; // 递归一定要先记得Base case

    curr += node->val;
    int count = prefix[curr - target];

    prefix[curr]++;
    count += dfs(node->left, curr);
    count += dfs(node->right, curr);
    prefix[curr]--; // 回溯

    return count;
  }

public:
  int pathSum(TreeNode *root, int targetSum)
  {
    prefix[0] = 1;
    target = targetSum;
    return dfs(root, 0);
  }
};