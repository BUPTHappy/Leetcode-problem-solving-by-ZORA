#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    string result;
    serializeHelper(root, result);
    return result;
  }

private:
  void serializeHelper(TreeNode *root, string &result)
  {
    if (!root)
    {
      result += "#,";
    }
    else
    {
      result += to_string(root->val) + ",";
      serializeHelper(root->left, result);
      serializeHelper(root->right, result);
    }
  }

public:
  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    stringstream ss(data);
    return deserializeHelper(ss);
  }

private:
  TreeNode *deserializeHelper(stringstream &ss)
  {
    string token;
    getline(ss, token, ',');

    if (token.empty() || token == "#")
    {
      return nullptr;
    }
    else
    {
      TreeNode *head = new TreeNode(stoi(token));
      head->left = deserializeHelper(ss);
      head->right = deserializeHelper(ss);
      return head;
    }
  }
};
