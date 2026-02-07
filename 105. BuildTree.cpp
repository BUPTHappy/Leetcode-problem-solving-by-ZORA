#include <unordered_map>
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

class Solution
{
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    unordered_map<int, int> record;
    for (int i = 0; i < inorder.size(); i++)
    {
      record.insert({inorder[i], i});
    }
    return f(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size(), record);
  }

private:
  TreeNode *f(vector<int> &preorder, int l1, int r1, vector<int> &inorder, int l2, int r2, unordered_map<int, int> &record)
  {
    if (l1 > r1)
    {
      return nullptr;
    }
    TreeNode *head = new TreeNode(preorder[l1]);
    if (l1 == r1)
    {
      return head;
    }
    int k = record[preorder[l1]];
    head->left = f(preorder, l1 + 1, l1 + k - l2, inorder, l2, k - 1, record);
    head->right = f(preorder, l1 + k - l2 + 1, r1, inorder, k + 1, r2, record);
    return head;
  }
};