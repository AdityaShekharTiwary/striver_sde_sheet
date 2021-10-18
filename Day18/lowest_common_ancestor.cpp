/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool solve(TreeNode* root, vector<TreeNode*> &path, TreeNode* target) {
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;
        if ((solve(root->left, path, target)) || (solve(root->right, path, target))) return true;
        path.pop_back();
        return false;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        solve(root, pathP, p);
        solve(root, pathQ, q);
        TreeNode* ans = nullptr;
        for (int i = 0; i < min(pathP.size(), pathQ.size()); i++) {
            if (pathP[i] == pathQ[i]) {
                ans = pathP[i];
            }
        }
        return ans;
    }
};