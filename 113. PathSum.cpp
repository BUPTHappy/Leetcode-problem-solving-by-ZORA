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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<vector<int>> ans;
    if (root)
    {
      vector<int> path;
      int sum = 0;
      f(root, sum, targetSum, path, ans);
    }
    return ans;
  }

  void f(TreeNode *root, int sum, int targetSum, vector<int> path, vector<vector<int>> &ans)
  { // 这里要注意是引用传递，不然每次都会是一个新的，如果你要修改同一份的话
    if (!root->left && !root->right)
    { // 当前节点是叶子节点
      if (sum + root->val == targetSum)
      {
        path.push_back(root->val);
        ans.push_back(path);
        path.pop_back();
      }
    }
    else
    { // 当前节点不是叶子节点
      path.push_back(root->val);
      if (root->left)
      {
        f(root->left, sum + root->val, targetSum, path, ans);
      }
      if (root->right)
      {
        f(root->right, sum + root->val, targetSum, path, ans);
      }
      path.pop_back();
    }
  }
};