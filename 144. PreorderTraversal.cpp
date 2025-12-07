//
// Created by Zhuoer LIU on 2025-12-07.
//
#include <TreeNode>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return{};

        ans.push_back(root->val);
        vector<int>left = preorderTraversal(root->left);
        vector<int>right =preorderTraversal(root->right);

        //注意，因为这里我们需要把结果压入数组，每次调用记得和之前的做一个结果拼接
        ans.insert(ans.end(), left.begin(), left.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};