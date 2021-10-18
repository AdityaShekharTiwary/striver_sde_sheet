class Solution {
public:
  // Function to return the diameter of a Binary Tree.
  int ans;
  int help(Node* root) {
    if (!root) return 0;
    int left = help(root->left);
    int right = help(root->right);
    ans = max(ans, left + right + 1);
    return max(left, right) + 1;
  }

  int diameter(Node* root) {
    ans = INT_MIN;
    help(root);
    return ans;
  }
};