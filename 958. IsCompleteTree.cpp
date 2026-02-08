#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


static int MAXN = 100;
vector<TreeNode *> queue_tool(MAXN);

class Solution
{
public:
  bool isCompleteTree(TreeNode *root)
  {
    int l = 0, r = 0;
    queue_tool[r++] = root;
    bool has_no_complete = false;
    while (l < r)
    {
      root = queue_tool[l++];
      if (!root)
      {
        return true;
      }

      if ((root->right && !root->left) ||
          (has_no_complete && (root->left || root->right)))
      {
        return false;
      }

      if (root->left)
      {
        queue_tool[r++] = root->left;
      }
      if (root->right)
      {
        queue_tool[r++] = root->right;
      }
      if (!root->left || !root->right)
      {
        has_no_complete = true;
      }
    }
    return true;
  }
};