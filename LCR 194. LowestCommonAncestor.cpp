struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (!root || root == p || root == q)
    {
      // 遇到空，或者直接遇到p或者q，就直接返回
      return root;
    }

    // 去左树搜索p和q：遇到空，或者直接遇到p或者q，就直接返回
    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    // 去右树搜索p和q：遇到空，或者直接遇到p或者q，就直接返回
    TreeNode *r = lowestCommonAncestor(root->right, p, q);

    if (l && r)
    {              // 如果左也在右也在（就是情况2）
      return root; // 不返回二者，返回其根
    }

    if (!l && !r)
    { // 如果左不在右也不在
      return nullptr;
    }

    return l != nullptr ? l : r; // 剩下的就是只有一个在，谁在返回谁
  }
};