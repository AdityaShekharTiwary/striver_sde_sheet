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
    bool ans;

    int helper(TreeNode* root) {
        if (!root) return 0;
        else return 1 + max(helper(root->left), helper(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = helper(root->left);
        int right = helper(root->right);
        if (abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return 1;
        return 0;
    }
};