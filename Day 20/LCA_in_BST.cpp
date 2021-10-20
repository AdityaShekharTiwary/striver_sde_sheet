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

    vector<TreeNode*> pathP, pathQ;

    bool findpath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path) {
        if (!root) return false;
        path.push_back(root);
        if (root == target) return true;
        if (findpath(root->left, target, path) || findpath(root->right, target, path)) return true;
        path.pop_back();
        return false;


    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findpath(root, p, pathP);
        findpath(root, q, pathQ);
        TreeNode* ans = nullptr;
        for (int i = 0; i < min(pathP.size(), pathQ.size()); i++) {
            if (pathP[i] == pathQ[i]) ans = pathP[i];
        }
        return ans;
    }
};


// SC : O(1)


TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if ((root->data > P->data) && (root->data > Q->data)) return LCAinaBST(root->left, P, Q);
    if ((root->data < P->data) && (root->data < Q->data)) return LCAinaBST(root->right, P, Q);
    return root;
}