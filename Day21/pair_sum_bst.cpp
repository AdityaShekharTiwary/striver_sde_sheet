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

    vector<int> arr;
    void solve(TreeNode* root) {
        if (!root) return;
        solve(root->left);
        arr.push_back(root->val);
        solve(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        solve(root);
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            if (arr[l] + arr[r] == k) return true;
            else if (arr[l] + arr[r] < k) l++;
            else r--;
        }
        return false;
    }
};