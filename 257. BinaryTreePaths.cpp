#include <vector>
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
  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> ans;
    dfs(root, "", ans);
    return ans;
  }

private:
  void dfs(TreeNode *node, string s, vector<string> &ans)
  {
    if (!node)
      return;

    s += to_string(node->val);

    if (!node->left && !node->right)
    {
      ans.push_back(s);
      return;
    }

    s += "->";
    dfs(node->left, s, ans);
    dfs(node->right, s, ans);
  }
};