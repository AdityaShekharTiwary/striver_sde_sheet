class Solution {
public:

    int idx;
    unordered_map<int, int> hash;

    Node* solve(int in[], int pre[], int l, int r) {
        if (l > r) return nullptr;
        Node* res = new Node(pre[idx++]);
        if (l == r) return res;
        int mid = hash[res->data];
        res->left = solve(in, pre, l, mid - 1);
        res->right = solve(in, pre, mid + 1, r);
        return res;
    }

    Node* buildTree(int in[], int pre[], int n)
    {
        idx = 0;
        hash.clear();
        for (int i = 0; i < n; i++) hash[in[i]] = i;
        Node* root = solve(in, pre, 0, n - 1);
        return root;
    }
};
