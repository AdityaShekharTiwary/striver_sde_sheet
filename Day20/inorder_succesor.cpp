class Solution {
public:
    vector<Node*> in;
    void solve(Node* root) {
        if (!root) return;
        solve(root->left);
        in.push_back(root);
        solve(root->right);
    }
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        solve(root);
        int cnt = 0;
        for (auto it : in) {
            if (cnt == 1) return it;
            if (it == x) {
                cnt++;
            }

        }
        return nullptr;
    }
};