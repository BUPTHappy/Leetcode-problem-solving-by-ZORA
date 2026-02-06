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
  int l, r;
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;
    bool reverse = false; // FALSE的时候是从左往右遍历
    if (root)
    {
      l = r = 0;
      queue_tool[r++] = root;

      while (l < r)
      {
        int size = r - l;
        vector<int> layer;

        // 主要就是变动从队列取出的顺序（按照锯齿形的规则）
        for (int i = reverse ? r - 1 : l, j = reverse ? -1 : 1, k = 0; k < size; i += j, k++)
        {
          TreeNode *cur = queue_tool[i];
          layer.push_back(cur->val);
        }

        // 然后第二步放左和右的操作不变
        for (int i = 0; i < size; i++)
        {
          TreeNode *cur = queue_tool[l++];
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
        reverse = !reverse; // 这里记得把flag更新一下
      }
    }
    return ans;
  }
};