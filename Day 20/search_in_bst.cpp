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

    TreeNode* ans;
    void solve(TreeNode* root, int target) {
        if (!root) return ;
        if (root->val == target) ans = root;
        if (root->val > target) solve(root->left, target);
        if (root->val < target) solve(root->right, target);

    }
    TreeNode* searchBST(TreeNode* root, int val) {
        ans = nullptr;
        solve(root, val);
        return ans == nullptr ? nullptr : ans;

    }
};