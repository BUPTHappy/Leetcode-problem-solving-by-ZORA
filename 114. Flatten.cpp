
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
  void flatten(TreeNode *root)
  {
    preOrder(root);
  }

  void preOrder(TreeNode *root)
  {
    if (!root)
    {
      return;
    }
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    root->left = nullptr;
    root->right = left;

    preOrder(left);
    preOrder(right);

    TreeNode *cur = root;
    while (cur->right)
      cur = cur->right; // 这是拼接后的循环，会在断掉的位置停下来，这就是我们需要续上的地方
    cur->right = right;
  }
};