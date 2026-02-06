#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static int MAXN = 2001;
vector<TreeNode *> queue_tool(MAXN);

class Solution
{
public:
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    int l, r;
    vector<vector<int>> ans;
    if (root)
    {
      l = r = 0;
      queue_tool[r++] = root;
      while (l < r)
      {
        int size = r - l;
        vector<int> layer;
        for (int i = 0; i < size; i++)
        {
          TreeNode *cur = queue_tool[l++];
          layer.push_back(cur->val);
          if (cur->left)
          {
            queue_tool[r++] = cur->left;
          }
          if (cur->right)
          {
            queue_tool[r++] = cur->right;
          }
        }

        ans.push_back(layer);
      }
    }
    return ans;
  }
};