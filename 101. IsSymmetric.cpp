
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
  bool isSymmetric(TreeNode *root)
  {
    return root == nullptr || symmetric(root->left, root->right);
  }

  bool symmetric(TreeNode *left, TreeNode *right)
  {
    if (left == nullptr && right == nullptr)
      return true;
    if (left == nullptr || right == nullptr || left->val != right->val)
      return false;
    return symmetric(left->left, right->right) && symmetric(left->right, right->left);
  }
};