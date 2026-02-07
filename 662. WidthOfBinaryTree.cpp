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

static int MAXN = 3001;
vector<TreeNode *> nq(MAXN);
vector<unsigned int> iq(MAXN);
int l, r;

class Solution
{
public:
  int widthOfBinaryTree(TreeNode *root)
  {
    l = r = 0;
    nq[r] = root;
    iq[r++] = 1;
    int ans = 0;
    while (l < r)
    {
      ans = max(ans, (int)(iq[r - 1] - iq[l] + 1));
      int size = r - l;
      for (int i = 0; i < size; i++)
      {
        TreeNode *cur = nq[l];
        unsigned int id = iq[l++];

        if (cur->left)
        {
          nq[r] = cur->left;
          iq[r++] = id * 2;
        }
        if (cur->right)
        {
          nq[r] = cur->right;
          iq[r++] = id * 2 + 1;
        }
      }
    }

    return ans;
  }
};