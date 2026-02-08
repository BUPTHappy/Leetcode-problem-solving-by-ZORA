
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
  int countNodes(TreeNode *root)
  {
    if (!root)
      return 0;
    return f(root, 0, mostLeft(root, 0));
  }

  int f(TreeNode *root, int level, int height)
  {
    if (level == height)
    {
      return 1;
    }

    if (mostLeft(root->right, level + 1) == height)
    { // 如果当前根的右树扎到了整棵树的高度
      // 说明当前根的左树是满二叉树,左树的节点按公式先加进去再递归右树
      return (1 << (height - level)) + f(root->right, level + 1, height);
    }
    else
    { // 如果右侧树没有扎到最深，能确定的是右树的节点数
      return (1 << (height - level - 1)) + f(root->left, level + 1, height);
      // 这里的2^这么多次方是合理的，要不然就不是完全二叉树了
    }
  }

  // 传入要查的头节点和当前头节点在的层数
  int mostLeft(TreeNode *head, int level)
  {
    while (head)
    {
      level++;
      head = head->left;
    }
    return level - 1; // 返回从该头节点一直往左扎到的最深深度
  }
};